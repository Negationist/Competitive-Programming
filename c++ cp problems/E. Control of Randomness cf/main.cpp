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
    int n, q;
    cin >> n >> q;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vector<int> par(n);
    auto dfs = [&](auto self, int cur, int p)->void{
        par[cur] = p;
        for(int x : adj[cur]){
            if(x!=p){
                self(self, x, cur);
            }
        }
    };
    dfs(dfs,0,-1);
    vi E(n);
    for(int i=1;i<n;i++){
        E[i] = 2*adj[i].size()-1;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    while(q--){
        while(pq.size()) pq.pop();
        int ans = 1;
        int v,p;
        cin >> v >> p;
        v--;
        v = par[v];
        while(v!=0){
            pq.push(E[v]);
            if(par[v]==0) break;
            ans++;
            if(par[par[v]]==0) break;
            v = par[par[v]];
        }
        while(pq.size()>p){
            ans+=pq.top();
            pq.pop();
        }
        cout << ans+pq.size() << "\n";
    }
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
