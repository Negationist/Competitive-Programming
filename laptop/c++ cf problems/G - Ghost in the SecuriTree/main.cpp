#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void dfs(int cur, set<int> &visited, vector<vi> &path, vector<vi> &adj, int last){
    visited.insert(cur);
    for(int x : visited){
        path[cur].pb(x);
    }
    for(int x : adj[cur]){
        if(x!=last){
            dfs(x, visited, path, adj, cur);
        }
    }
    visited.erase(cur);
}

void solve(){
    int n,q,r;
    cin >> n >> q >> r;
    r--;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<vi> path(n);
    set<int> visited;
    dfs(r, visited, path, adj, -1);
    for(int i=0;i<n;i++){
        cout << "path to " << i+1 << " is ";
        for(int x : path[i]){
            cout << x+1 << " ";
        }
        cout << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
