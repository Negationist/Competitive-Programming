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
    vi a(n),b(n);
    vector<vii> adj(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        b[i]--;
        adj[i].pb({b[i],a[i]});
        if(i>0) adj[i].pb({i-1,0});
    }
    vi pref(n+1);
    pref[0] = 0;
    for(int i=1;i<n+1;i++){
        pref[i] = pref[i-1]+a[i-1];
    }
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
    int ans = -1;
    for(int i=0;i<n;i++){
        int res = pref[i+1]-distance[i];
        ans = max(res,ans);
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
