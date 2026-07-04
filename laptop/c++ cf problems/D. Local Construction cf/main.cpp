#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n;
    cin >> n;
    map<int,vi> pos;
    deque<int> q;
    int mx = -1;
    int last;
    vi ans(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        mx = max(mx,z);
        if(z==-1){
            last = i;
        } else{
            pos[z].pb(i);
        }
        q.push_back(i+1);
    }
    pos[mx+1].pb(last);
    for(int i=1;i<=mx;i++){ //1st is mins stay
        int mark = pos[i+1].back();
        if(i&1){ //NO MINS
            for(int j=pos[i].size()-1;j>=0;j--){
                int index = pos[i][j];
                if(index>mark){
                    ans[index] = q.back();
                    q.pop_back();
                }
            }
            for(int j=0;j<pos[i].size();j++){
                int index = pos[i][j];
                if(index<mark){
                    ans[index] = q.back();
                    q.pop_back();
                }
            }
        } else{ //NO MAXES
            for(int j=pos[i].size()-1;j>=0;j--){
                int index = pos[i][j];
                if(index>mark){
                    ans[index] = q.front();
                    q.pop_front();
                }
            }
            for(int j=0;j<pos[i].size();j++){
                int index = pos[i][j];
                if(index<mark){
                    ans[index] = q.front();
                    q.pop_front();
                }
            }
        }
    }
    ans[last] = q.front();
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
