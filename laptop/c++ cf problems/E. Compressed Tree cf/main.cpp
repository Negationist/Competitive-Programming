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

const int inf = 1LL<<50;

void solve(){
    int n;
    cin >> n;
    vi val(n);
    int mx = -inf;
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vector<vi> dp(n,vi(4,-inf));
    int ans = -inf;
    auto dfs = [&](auto self, int x, int p)->void{
        vi cands;
        for(int y : adj[x]){
            if(y!=p){
               self(self,y,x);
               int res = max(max(dp[y][0],dp[y][1]-val[y]),max(dp[y][2]+val[y],dp[y][3]));
               cands.pb(res);
            }
        }
        sort(cands.begin(),cands.end(),greater<int>());
        dp[x][0] = val[x];
        int z = cands.size();
        for(int i=1;i<=3;i++){
            if(i==1 && z>=1){
                dp[x][i] = cands[0]+val[x];
            } else if(i==2 && z>=2){
                dp[x][i] = cands[0]+cands[1];
            } else if(i==3 && z>=3){
                dp[x][i] = val[x];
                for(int j=0;j<z;j++){
                    if(j<3){
                        dp[x][i]+=cands[j];
                    } else{
                        if(cands[j]>0){
                            dp[x][i]+=cands[j];
                        }
                    }
                }
            }
        }
    };
    dfs(dfs,0,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            ans = max(ans,dp[i][j]);
        }
    }
    cout << max(ans,0LL) << "\n";
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
