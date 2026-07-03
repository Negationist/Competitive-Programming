#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<62;
void solve(){
    int n,m;
    cin >> n >> m;
    int s,t;
    cin >> s >> t;
    --s; --t;
    int u,v;
    cin >> u >> v;
    --u;--v;
    vector<vii> adj(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[--a].pb({--b,c});
        adj[b].pb({a,c});
    }
    vi distanceS(n,inf),distanceU(n,inf),distanceV(n,inf);
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<bool> visited(n,false);
    distanceU[u] = 0;
    pq.push({0,u});
    while(pq.size()){
        int a = pq.top().second;
        pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto x : adj[a]){
            int b = x.first,w=x.second;
            if(distanceU[a]+w<distanceU[b]){
                distanceU[b] = distanceU[a]+w;
                pq.push({distanceU[b],b});
            }
        }
    }
    visited.assign(n,false);
    distanceV[v] = 0;
    pq.push({0,v});
    while(pq.size()){
        int a = pq.top().second;
        pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto x : adj[a]){
            int b = x.first,w=x.second;
            if(distanceV[a]+w<distanceV[b]){
                distanceV[b] = distanceV[a]+w;
                pq.push({distanceV[b],b});
            }
        }
    }
    visited.assign(n,false);
    vi ogmn(n),mn1(n);
    for(int i=0;i<n;i++){
        ogmn[i] = distanceV[i];
        mn1[i] = distanceV[i];
    }
    distanceS[s] = 0;
    pq.push({0,s});
    while(pq.size()){
        int a = pq.top().second;
        pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto x : adj[a]){
            int b = x.first,w=x.second;
            if(distanceS[a]+w<distanceS[b]){
                distanceS[b] = distanceS[a]+w;
                pq.push({distanceS[b],b});
                mn1[b] = min(mn1[a],ogmn[b]);
            } else if(distanceS[a]+w==distanceS[b]){
                mn1[b] = min(mn1[b],mn1[a]);
            }
        }
    }
    vi distanceT(n,inf);
    vi mn2(n);
    for(int i=0;i<n;i++){
        mn2[i] = distanceV[i];
    }
    distanceT[t] = 0;
    pq.push({0,t});
    visited.assign(n,false);
    while(pq.size()){
        int a = pq.top().second;
        pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto x : adj[a]){
            int b = x.first,w=x.second;
            if(distanceT[a]+w<distanceT[b]){
                distanceT[b] = distanceT[a]+w;
                pq.push({distanceT[b],b});
                mn2[b] = min(mn2[a],ogmn[b]);
            } else if(distanceT[a]+w==distanceT[b]){
                mn2[b] = min(mn2[b],mn2[a]);
            }
        }
    }
    /*for(int i=0;i<n;i++){
        cout << "for: " << i+1 << "distance to u is " << distanceU[i] << ". distance to v is " << distanceV[i];
        cout << "distance to t is " << distanceT[i] << ". mn to v is " << mn[i] << "\n";
    }*/
    int len = distanceS[t];
    int ans = inf;
    for(int i=0;i<n;i++){
        int res = distanceS[i]+distanceT[i];
        if(res==len){
            int cur = distanceU[i]+min(mn1[i],mn2[i]);
            if(s==u){
                cur-=distanceU[i];
            }
            ans = min(ans,cur);
        }
    }
    ans = min(ans,distanceU[v]);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
