#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void dfs (int cur, set<int>&unvisited, int p, vector<set<int>> &adj){
    unvisited.erase(cur);
    for(int x : adj[cur]){
        if(x!=p){
            dfs(x,unvisited,cur, adj);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    stack<int> s;
    for(int i=0;i<n;i++){
        if(adj[i].size()>1){
            s.push(i);
        }
    }
    vector<tuple<int,int,int>> ans;
    while(s.size()){
        int cur = s.top();
        s.pop();
        if(adj[cur].size()<2) continue;
        int x = *adj[cur].begin();
        adj[cur].erase(x);
        int y = *adj[cur].begin();
        adj[cur].erase(y);
        adj[x].erase(cur);
        adj[y].erase(cur);
        ans.pb({cur,x,y});
        if(adj[x].find(y) == adj[x].end()){
            adj[x].insert(y);
            adj[y].insert(x);
        } else{
            adj[x].erase(y);
            adj[y].erase(x);
        }
        if(adj[cur].size()>1){
            s.push(cur);
        }
        if(adj[x].size()>1){
            s.push(x);
        }
        if(adj[y].size()>1){
            s.push(y);
        }
    }
    set<int> unvisited;
    for(int i=0;i<n;i++){
        unvisited.insert(i);
    }
    set<int> alone;
    int root = -1;
    while(unvisited.size()){
        int next = *unvisited.begin();
        alone.insert(next);
        if(adj[next].size()) root = next;
        dfs(next,unvisited, -1,adj);
    }
    alone.erase(root);
    while(alone.size() && root!=-1){
        int x = root;
        int y = *adj[root].begin();
        int z = *alone.begin();
        adj[x].erase(y);
        adj[y].erase(x);
        adj[x].insert(z);
        adj[y].insert(z);
        adj[z].insert(x);
        adj[z].insert(y);
        root = z;
        ans.pb({x,y,z});
        alone.erase(z);
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << get<0>(x)+1 << " " << get<1>(x)+1 << " " << get<2>(x)+1 << "\n";
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
