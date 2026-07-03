#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<60;
void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = 1;
    vector<int> dp(n);
    auto dfs = [&](auto self, int cur, int p)->void{
        int one = -1;
        int two = -1;
        dp[cur] = adj[cur].size();
        for(int x : adj[cur]){
            if(x!=p){
                self(self, x, cur);
                if(dp[x]>one){
                    two = one;

                    one = dp[x];
                } else if(dp[x]>two){
                    two = dp[x];
                }
                int res = dp[x]+adj[cur].size()-2LL;
                dp[cur] = max(dp[cur], res);
            }
        }
        ans = max(ans,dp[cur]);
        int res = one+two+adj[cur].size()-4;
        if(two!=-1) ans = max(ans,res);
    };
    dfs(dfs, 0,-1);
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
