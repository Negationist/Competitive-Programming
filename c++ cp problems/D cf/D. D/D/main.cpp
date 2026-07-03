#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;

const int inf = 1LL<<50;

void solve(){
    int n,m,l;
    cin >> n >> m >> l;
    int sum = 0, small = inf;
    for(int i=0;i<l;i++){
        int z;
        cin >> z;
        sum+=z;
        if(z&1){
            small = min(small,z);
        }
    }
    int sum_even, sum_odd;
    if(sum&1){
        sum_odd = sum;
        sum_even = sum-small;
    } else{
        sum_even = sum;
        sum_odd = sum-small;
    }
    vector<vi> adj(n);
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    vector<vi> distance(n,vi(2,inf));
    queue<pair<pii,int>> q;
    q.push({{0,0},0});
    while(q.size()){
        int x = q.front().ff.ff, p = q.front().ff.ss, dist = q.front().ss;
        q.pop();
        if(distance[x][p]!=inf) continue;
        distance[x][p] = dist;
        for(int y : adj[x]){
            if(distance[y][p^1]==inf){
                q.push({{y,p^1},dist+1});
            }
        }
    }
    vi ans(n,0);
    for(int i=0;i<n;i++){
        if(distance[i][0]<=sum_even){
            ans[i] = 1;
        }
        if(distance[i][1]<=sum_odd){
            ans[i] = 1;
        }
        cout << ans[i];
    }
    cout << "\n";
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
