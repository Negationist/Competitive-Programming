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
const int inf = 1LL<<30;
void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    if(n==2){
        cout << 2 << "\n";
        return;
    }
    int root;
    for(int i=0;i<n;i++){
        if(adj[i].size()>1){
            root = i;
            break;
        }
    }
    vector<vector<vi>> dp(n,vector<vi>(2,vi(2,0)));
    auto dfs = [&](auto self, int x, int p)->void{
        dp[x][1][1]=1;
        dp[x][1][0]=1;
        bool is = true;
        int mn1 = inf;
        int mn2 = inf;
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
                is = false;
                dp[x][0][1]+=max(dp[y][0][1],dp[y][1][1]);
                dp[x][1][1]+=dp[y][0][1];
                dp[x][1][0]+=max(dp[y][0][0],dp[y][0][1]);
                mn1 = min(mn1,dp[y][0][1]-dp[y][0][0]);
                int mx_leafs = max(dp[y][0][1],dp[y][1][1]);
                int mx_no_leafs = max(dp[y][1][0],dp[y][0][0]);
                dp[x][0][0]+=max(mx_leafs,mx_no_leafs);
                mn2 = min(mn2,mx_leafs-mx_no_leafs);
            }
        }
        if(is){
            dp[x][0][0] = 0;
            dp[x][0][1] = -inf;
            dp[x][1][0] = -inf;
            dp[x][1][1] = 1;
        } else{
            dp[x][1][0]-=max(mn1,0LL);
            dp[x][0][0]-=max(mn2,0LL);
        }
    };
    dfs(dfs,root,-1);
    int ans = max(max(dp[root][0][0]+1,dp[root][1][0]+1),max(dp[root][0][1],dp[root][1][1]));
    cout << ans << "\n";
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
