#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

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
    vector<int> dp(n,-inf);
    int ans = dp[0] = adj[0].size();
    auto dfs = [&](auto self, int cur, int p)->void{
        if(p!=-1){
            int first = dp[p]+adj[cur].size()-2;
            int second = adj[cur].size();
            dp[cur] = max(first,second);
            ans = max(ans, dp[cur]);
        }
        for(int x : adj[cur]){
            if(x!=p){
                self(self, x, cur);
            }
        }
    };
    dfs(dfs,0,-1);
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
