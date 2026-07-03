#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

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
    if(n==2){
        cout << "2 2\n 1 1\n";
        return;
    }
    vector<vii> dp(n, vii(2)); //{-good, sum}
    auto dfs = [&](auto self, int cur, int p ) -> void {
        dp[cur][0].ff = 0;
        dp[cur][0].ss = 1;
        dp[cur][1].ff = -1;
        dp[cur][1].ss = adj[cur].size();
        for(int x : adj[cur]){
            if(x==p) continue;
            self(self, x, cur);
            if(dp[x][0]<dp[x][1]){
                dp[cur][0].ff+=dp[x][0].ff;
                dp[cur][0].ss+=dp[x][0].ss;
            } else{
                dp[cur][0].ff+=dp[x][1].ff;
                dp[cur][0].ss+=dp[x][1].ss;
            }
            dp[cur][1].ff+=dp[x][0].ff;
            dp[cur][1].ss+=dp[x][0].ss;
        }
    };
    dfs(dfs,0,-1);
    vector<int> ans(n,1);
    auto make = [&](auto self, int cur, int p, int good) -> void {
        if(good){
            ans[cur] = adj[cur].size();
        }
        if(!good){
            for(int x : adj[cur]){
                if(x==p) continue;
                if(dp[x][0]<dp[x][1]){
                    self(self, x, cur, 0);
                } else{
                    self(self, x, cur, 1);
                }
            }
        } else{
            for(int x : adj[cur]){
                if(x==p) continue;
                self(self, x, cur, 0);
            }
        }
    };
    if(dp[0][0]<dp[0][1]){
        cout << -dp[0][0].ff << " " << dp[0][0].ss << "\n";
        make(make, 0, -1, 0);
    } else{
        cout << -dp[0][1].ff << " " << dp[0][1].ss << "\n";
        make(make, 0, -1, 1);
    }
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
