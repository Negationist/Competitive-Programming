#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int mn;

void dfs(int cur, vector<vector<pair<int,char>>> &adj, vector<bool> &visited, int sum, string &s){
    if(adj[cur].size()==0) mn = min(mn, sum);
    visited[cur] = true;
    for(auto x : adj[cur]){
        if(visited[x.first] ==  true) continue;
        if(s[cur]==x.second){
            dfs(x.first, adj, visited, sum, s);
        } else{
            dfs(x.first, adj, visited, sum+1, s);
        }
    }
}

void solve(){
    mn = LLONG_MAX;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<pair<int,char>>> adj(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a!=0){
            adj[i].pb({a-1,'L'});
        }
        if(b!=0){
            adj[i].pb({b-1,'R'});
        }
    }
    vector<bool> visited(n, false);
    dfs(0,adj, visited, 0, s);
    cout << mn << "\n";
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
