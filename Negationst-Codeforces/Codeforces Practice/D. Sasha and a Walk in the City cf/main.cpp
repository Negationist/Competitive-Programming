#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 998244353;
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
    vii dp(n);
    auto dfs = [&](auto self, int cur, int p)->void{
        bool is = true;
        int prod = 1;
        int sum1 = 0;
        int sum2 = 0;
        for(int x : adj[cur]){
            if(x!=p){
                is = false;
                self(self,x,cur);
                prod*=(dp[x].ff+1);
                sum1+=dp[x].ff;
                sum2+=dp[x].ss;
                prod%=mod;
                sum1%=mod;
                sum2%=mod;
            }
        }
        dp[cur].ff = prod; //-1 for null set +1 for aloneness
        dp[cur].ss = sum2; //pick one child with one ancestor pair
        dp[cur].ss+=sum1; //pick root and child no ancestor
        if(is){
            dp[cur].ff = 1;
            dp[cur].ss = 0;
        }
        dp[cur].ff%=mod;
        dp[cur].ss%=mod;
    };
    dfs(dfs,0,-1);
    int ans = dp[0].ff+dp[0].ss+1;
    cout << ans%mod << "\n";
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
