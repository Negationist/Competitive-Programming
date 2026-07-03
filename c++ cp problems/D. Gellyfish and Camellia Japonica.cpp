#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<set<int>> vals(n);
    while(q--){
        int x,y,z;
        cin >> x >> y >> z;
        --x; --y; --z;
        if(a[z]>min(a[x],a[y])){
            bool one = (a[z]>a[x]), two = (a[z]>a[y]);
            if(one && two){
                if(!vals[x].size() || !vals[y].size()){
                    cout << "-1\n";
                    return;
                } else{
                    if(vals[x].find(y)!=vals[x].end()){
                        cout << "-1\n";
                        return;
                    } else{
                        a[x] = a[y] = a[z];
                        vals[x].insert(y);
                        vals[y].insert(x);
                        vals[x].erase(-1);
                        vals[y].erase(-1);
                    }
                }
            }
            if(one){
                if(!vals[x].size()){
                    cout << "-1\n";
                    return;
                }
                a[x] = a[z];
                if(a[y]==a[z] && vals[y].size()){ //y is not alr to big and y can be raised
                    vals[x].insert(y);
                    vals[y].insert(x);
                    vals[x].erase(-1);
                    vals[y].erase(-1);
                } else{
                    for(int num : vals[x]){
                        if(num!=-1){
                            vals[num].clear();
                        }
                    }
                    vals[x].clear();
                }
            } else{
                if(!vals[y].size()){
                    cout << "-1\n";
                    return;
                }
                a[y] = a[z];
                if(a[x]==a[z] && vals[x].size()){ //x is not alr to big and x can be raised
                    vals[x].insert(y);
                    vals[y].insert(x);
                    vals[x].erase(-1);
                    vals[y].erase(-1);
                } else{
                    for(int num : vals[y]){
                        if(num!=-1){
                            vals[num].clear();
                        }
                    }
                    vals[y].clear();
                }
            }
        } else if(a[z]<min(a[x],a[y])){
            if(!vals[z].size()){
                cout << "-1\n";
                return;
            } else{
                a[z] = min(a[x],a[y]);
                
            }
        }
    }
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