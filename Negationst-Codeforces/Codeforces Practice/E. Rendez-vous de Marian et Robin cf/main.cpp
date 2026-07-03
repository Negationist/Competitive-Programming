#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
vector<vii> adj;
vector<bool> visited;
void solve(){
    int n,m,hor;
    cin >> n >> m >> hor;
    adj.assign(n,vii());
    visited.assign(n,false);
    set<int> h;
    for(int i=0;i<hor;i++){
        int a;
        cin >> a;
        h.insert(a-1);
    }
    for(int i=0;i<m;i++){
        int u,v,weight;
        cin >> u >> v >> weight;
        adj[u-1].pb({v-1,weight});
        adj[v-1].pb({u-1,weight});
    }
    int distance[n];
    for(int i=0;i<n;i++) distance[i] = LLONG_MAX;
    priority_queue<pii> q2;
    distance[0] = 0;
    q2.push({0,0});
    while(!q2.empty()){
        int a = q2.top().second;
        q2.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto x : adj[a]){
            int b = x.first, w = x.second;
            if(distance[a]+w < distance[b]){
                distance[b] = distance[a]+w;
                q2.push({-distance[b],b});
            }
        }
    }
    int ans = distance[n-1];
    if(ans==LLONG_MAX){
        cout << -1 << "\n";
        return;
    }
    for(int x : h){
        int sum = distance[x];
        visited.assign(n,false);
        int distance2[n];
        for(int i=0;i<n;i++) distance2[i] = LLONG_MAX;
        distance2[x] = 0;
        priority_queue<pii> q;
        q.push({0,x});
        while(!q.empty()){
            int a = q.top().second;
            q.pop();
            if(visited[a]) continue;
            visited[a] = true;
            for(auto x : adj[a]){
                int b = x.first, w = x.second;
                if(distance2[a]+w < distance2[b]){
                    distance2[b] = distance2[a]+w;
                    q.push({-distance2[b],b});
                }
            }
        }
        if(distance[n-1]==LLONG_MAX);
        sum+=(distance2[n-1]/2);
        ans = min(ans, sum);
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
