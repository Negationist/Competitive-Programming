#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void djk(int s, vector<vii> &adj, vector<int> &distance){
    bool visited[adj.size()] = {};
    distance[s] = 0;
    priority_queue<pii> q;
    q.push({0,s});
    while(q.size()){
        int a = q.top().second; q.pop();
        if(visited[a] == true) continue;
        visited[a] = true;
        for(auto x : adj[a]){
            int b = x.first, w=x.second;
            if(distance[a]+w < distance[b]){
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
            }
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vii> adj(n);
    vi distance(n);
    for(int i=0;i<n;i++) distance[i] = LLONG_MAX;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    int start;
    cin >> start;
    djk(start, adj, distance);
    for(int i=0;i<n;i++){
        if(distance[i]==LLONG_MAX) cout << "unreachable\n";
        else cout << distance[i] << "\n";
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
