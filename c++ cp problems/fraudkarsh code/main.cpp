#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n, m, s, t, u, v;
vector<pair<ll, ll>> adj[MAXN];
void dijkstra(ll start, vector<ll> &dist)
{
    dist[start] = 0;
    vector<bool> visited(n + 1);
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        const auto[cdist, node] = pq.top();
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        for(const pair<ll, ll> &i: adj[node]){
            if(cdist + i.second < dist[i.first]){
                pq.push({dist[i.first] = cdist + i.second, i.first});
            }
        }
    }

}
vector<ll> dijkstra2(ll start, vector<ll> &dist, vector<ll> &cost)
{
    dist[start] = 0;
    vector<ll> min_cost(n + 1, LLONG_MAX);
    vector<bool> visited(n + 1);
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, start}); min_cost[start] = cost[start];
    while(!pq.empty()){
        const auto[cdist, node] = pq.top();
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        for(const pair<ll, ll> &i: adj[node]){
            if(cdist + i.second < dist[i.first]){
                min_cost[i.first] = min(cost[i.first], min_cost[node]);
                pq.push({dist[i.first] = cdist + i.second, i.first});
            }
            else if(cdist + i.second == dist[i.first]){
                min_cost[i.first] = min(cost[i.first], min(min_cost[i.first], min_cost[node]));
            }
        }
    }
    return min_cost;

}
int main()
{
    cin >> n >> m >> s >> t >> u >> v;
    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<ll> tdist(n + 1, LLONG_MAX);
    dijkstra(t, tdist);
    for(int i = 1; i <= n; i++){
        cout << tdist[i] << " ";
    }
    cout << "\n";
    vector<ll> sdist(n + 1, LLONG_MAX);
    dijkstra(s, sdist);
    vector<ll> vdist(n + 1, LLONG_MAX);
    vector<ll> udist(n + 1, LLONG_MAX);
    vector<ll> cost1 = dijkstra2(v, vdist, tdist);
    vector<ll> cost2 = dijkstra2(u, udist, tdist);
    ll res = 1e18;
    for(int i = 1; i <= n; i++){
        if(vdist[i] + udist[i] == vdist[u]){
            res = min(res, sdist[i] + min(cost1[i], cost2[i]));
        }
    }
    cout << res << "\n";
}
