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
const int mod = 998244353;
void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    vi p(n,-1);
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        --x;
        adj[i].pb(x);
        adj[x].pb(i);
        p[i] = x;
    }
    vector<vi> depths(n+5);
    auto dfs = [&](auto self, int x, int p, int d)->void{
        depths[d].pb(x);
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x,d+1);
            }
        }
    };
    dfs(dfs,0,-1,0);
    int sum[n+5] = {};
    int dp[n+5];
    int ans = 1;
    dp[0] = 1;
    sum[0] = 2;
    for(int i=1;i<n+5;i++){
        for(int x : depths[i]){
            dp[x] = (sum[i-1]-dp[p[x]]+10*mod)%mod;
            ans+=dp[x];
            ans%=mod;
            sum[i]+=dp[x];
            sum[i]%=mod;
        }
    }
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
