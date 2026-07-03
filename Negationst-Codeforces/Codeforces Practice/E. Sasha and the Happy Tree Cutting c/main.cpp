//jiangly goat, for now
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
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vi s(n);
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int u,v;
        cin >> u >> v;
        --u;
        --v;
        s[u]|=(1LL<<i);
        s[v]|=(1LL<<i);
    }
    vi useful;
    auto dfs = [&](auto self, int x, int p)->void{
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
                s[x]^=s[y];
            }
        }
        for(int y : adj[x]){
            if(y==p) continue;
            if(~s[x] & s[y]){
                useful.pb(s[y]);
            }
        }
    };
    dfs(dfs,0,-1);
    int states = (1LL<<k);
    vi dp(states,inf);
    dp[0] = 0;
    for(int i=1;i<states;i++){
        for(int j=0;j<useful.size();j++){
            dp[i] = min(dp[i],dp[i & ~useful[j]]+1);
        }
    }
    cout << dp[states-1] << "\n";
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
