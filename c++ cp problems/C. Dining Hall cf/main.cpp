#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
set<tuple<int,int,int>> cells_1,cells_0;

void _fill(){
    for(int x=0; x<sqrt(50000)+10;x++){
        for(int y=0; y<sqrt(50000)+10;y++){
            cells_1.insert({3*x+1+3*y+1,3*x+1,3*y+1});
            cells_1.insert({3*x+1+3*y+2,3*x+1,3*y+2});
            cells_1.insert({3*x+2+3*y+1,3*x+2,3*y+1});
            cells_1.insert({3*x+2+3*y+2,3*x+2,3*y+2});
        }
    }
    cells_0 = cells_1;
}

void solve(){
    set<tuple<int,int,int>> gone_0, gone_1;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int z; cin >> z;
        tuple<int,int,int> cur;
        if(z){
            cur = *cells_1.begin();
        } else{
            cur = *cells_0.begin();
        }
        cout << get<1>(cur) << " " << get<2>(cur) << "\n";
        cells_1.erase(cur);
        cells_0.erase(cur);
        gone_0.insert(cur);
        gone_1.insert(cur);
        for(int j=-1;j<=1;j++){
            for(int k=-1;k<=1;k++){
                tuple<int,int,int> temp = {get<0>(cur)+j+k,get<1>(cur)+j, get<2>(cur)+k};
                if(cells_0.find(temp)!=cells_0.end()){
                    cells_0.erase(temp);
                    gone_0.insert(temp);
                }
            }
        }
    }
    for(auto tup : gone_0){
        cells_0.insert(tup);
    }
    for(auto tup : gone_1){
        cells_1.insert(tup);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    _fill();
    while(t--){
        solve();
    }
    return 0;
}
