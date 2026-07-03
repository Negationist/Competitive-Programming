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
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    int mx = 0;
    int node;
    vi par(n,-1);
    auto dfs1 = [&](auto self, int cur, int p, int dis)->void{
        par[cur] = p;
        if(dis>mx){
            //cout << "dis to " << cur << " is " << dis << "\n";
            node = cur;
            //cout << "node is " << cur << "\n";
            mx = dis;
        }
        for(auto x : adj[cur]){
            if(x!=p){
                self(self,x,cur,dis+1);
            }
        }
    };
    dfs1(dfs1,0,-1,0);
    int root = node;
    mx = 0;
    dfs1(dfs1,node,-1,0);
    int leaf = node;
    vi ans(n+1);
    ans[1] = 1;
    ans[2] = mx+1;
    int cur = leaf;
    vector<int> dia(n,0);
    dia[root] = dia[leaf] = 1;
    while(cur!=root){
        dia[cur] = 1;
        cur = par[cur];
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
