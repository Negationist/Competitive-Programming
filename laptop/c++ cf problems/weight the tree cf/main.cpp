#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void dfs(int cur, int p, int d, vector<vi> &adj, vector<vi> &depths, vector<int> &lowness){
    depths[d].pb(cur);
    lowness[cur] = d;
    for(int x : adj[cur]){
        if(x!=p){
            dfs(x,cur,d+1,adj,depths,lowness);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    vector<vi> depths(n);
    vector<int> lowness(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1,0,adj,depths,lowness);
    vector<bool> good(n,false);
    vector<vii> dp(n, vii(2,{0,0}));
    for(int i=n-1;i>=0;i--){
        //choose good or bad children
        for(int x : depths[i]){
            for(int y : adj[x]){
                if(lowness[y]<lowness[x]) continue;
                dp[x][1].ff = 1;
                dp[x][1].ss = adj[x].size();
                dp[x][1].ff+=dp[y][0].ff;
                dp[x][1].ss+=dp[y][0].ss;
                dp[x][0].ff = 0;
                if(dp[y][0].ff>dp[y][1].ff){
                    dp[x][0].ff+=dp[y][0].ff;
                    dp[x][0].ss+=dp[y][0].ss;
                } else if(dp[y][0].ff<dp[y][1].ff){
                    dp[x][0].ff+=dp[y][1].ff;
                    dp[x][0].ss+=dp[y][1].ss;
                } else{
                    if(dp[y][0].ss<=dp[y][1].ss){
                        dp[x][0].ff+=dp[y][0].ff;
                        dp[x][0].ss+=dp[y][0].ss;
                    } else{
                        dp[x][0].ff+=dp[y][1].ff;
                        dp[x][0].ss+=dp[y][1].ss;
                    }
                }
            }
        }
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
