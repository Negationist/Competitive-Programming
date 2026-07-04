#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int inf = 1LL<<40;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vii> adj(n);
    vii edges;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[--a].pb({--b,w});
        adj[b].pb({a,w});
        edges.pb({a,b});
    }
    vii routes;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        routes.pb({--a,--b});
    }
    vector<vi> distance(n,vi(n,inf));
    for(int i=0;i<n;i++){
        vector<bool> visited(n,false);
        priority_queue<pii> pq;
        distance[i][i] = 0;
        pq.push({0,i});
        while(pq.size()){
            int a = pq.top().second;
            pq.pop();
            if(visited[a]) continue;
            visited[a] = true;
            for(auto x : adj[a]){
                int b = x.first,w=x.second;
                if(distance[i][a]+w<distance[i][b]){
                    distance[i][b] = distance[i][a]+w;
                    pq.push({-distance[i][b],b});
                }
            }
        }
    }
    int ans = inf;
    for(auto [a,b] : edges){
        int sum = 0;
        for(auto [c,d] : routes){
            int res1 = distance[c][d], res2 = distance[c][a]+distance[b][d];
            int res3 = distance[c][b]+distance[a][d];
            int res = min(res1,min(res2,res3));
            //cout << res1 << " " << res2 << " " << res3 << "\n";
            sum+=res;
        }
        ans = min(ans,sum);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
