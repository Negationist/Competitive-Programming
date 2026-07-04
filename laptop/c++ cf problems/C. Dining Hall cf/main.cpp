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
    int r = sqrtl(n);
    r*=2;
    vector<tuple<int,int,int>> pos;
    for(int x=0;x<=r;x++){
        for(int y=0;y<=r;y++){
            pos.pb({3*x+3*y+2,3*x+1,3*y+1});
            pos.pb({3*x+3*y+3,3*x+1,3*y+2});
            pos.pb({3*x+3*y+3,3*x+2,3*y+1});
            pos.pb({3*x+3*y+6,3*x+2,3*y+2});
        }
    }
    sort(pos.begin(),pos.end());
    vector<vi> vis(3*r+10,vi(3*r+10,0));
    int j = 0, k = 0;
    for(int i=0;i<n;i++){
        int z; cin >> z;
        if(z){
            while(true){
                int x = get<1>(pos[j]), y = get<2>(pos[j]);
                if(vis[x][y]>1){
                    ++j;
                    continue;
                } else{
                    for(int l=-1;l<=1;l++){
                        for(int m=-1;m<=1;m++){
                            vis[x+l][y+m] = max(vis[x+l][y+m],1LL);
                        }
                    }
                    vis[x][y] = 2;
                    cout << x << " " << y << "\n";
                    break;
                }
            }
        } else{
            while(true){
                int x = get<1>(pos[k]), y = get<2>(pos[k]);
                if(vis[x][y]!=0){
                    ++k;
                    continue;
                } else{
                    for(int l=-1;l<=1;l++){
                        for(int m=-1;m<=1;m++){
                            vis[x+l][y+m] = max(vis[x+l][y+m],1LL);
                        }
                    }
                    vis[x][y] = 2;
                    cout << x << " " << y << "\n";
                }
                break;
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
