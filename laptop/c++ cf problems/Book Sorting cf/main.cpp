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
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vector<vi> dp(n,vi(2));
    int ans = -1;
    auto dfs = [&](auto self, int x, int p)->void{
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
                dp[x][1]+=dp[y][0];
                dp[x][0]+=max(dp[y][0],dp[y][1]);
            }
        }
        dp[x][1]+=adj[x].size()-1;
        ans = max(ans,max(dp[x][0],dp[x][1]));
    };
    dfs(dfs,0,-1);
    cout << ans+2 << "\n";
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
