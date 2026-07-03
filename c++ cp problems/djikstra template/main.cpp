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
    //assumes input is given as a list of pairs as {n,w}, neighbor, weight and the first node is node 0
    priority_queue<pii> pq;
    vi distance(n,1LL<<60);
    vector<bool> visited(n,false);
    distance[0] = 0;
    pq.push({0,0});
    while(pq.size()){
        int a = pq.top().second;
        pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto x : adj[a]){
            int b = x.first,w=x.second;
            if(distance[a]+w<distance[b]){
                distance[b] = distance[a]+w;
                pq.push({-distance[b],b});
            }
        }
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
