#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
const int inf = 1LL<<60;
void solve(){
    int n,s1,s2;
    cin >> n >> s1 >> s2;
    --s1;
    --s2;
    int m1; cin >> m1;
    vector<vi> adj1(n,vi());
    for(int i=0;i<m1;i++){
        int a,b;
        cin >> a >> b;
        adj1[--a].pb(--b);
        adj1[b].pb(a);
    }
    int m2; cin >> m2;
    vector<vi> adj2(n,vi());
    for(int i=0;i<m2;i++){
        int a,b;
        cin >> a >> b;
        adj2[--a].pb(--b);
        adj2[b].pb(a);
    }
    vector<vector<vii>> adj(n, vector<vii>(n,vii()));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int x : adj1[i]){
                for(int y : adj2[j]){
                    adj[i][j].pb({x,y});
                }
            }
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vi> distance(n,vi(n,inf));
    distance[s1][s2] = 0;
    pq.push({0,{s1,s2}});
    while(pq.size()){
        int x = pq.top().ff;
        pii y = pq.top().ss;
        pq.pop();
        if(x!=distance[y.ff][y.ss]) continue;
        for(auto &[a,b] : adj[y.ff][y.ss]){
            if(distance[y.ff][y.ss]+abs(a-b)<distance[a][b]){
                distance[a][b] = distance[y.ff][y.ss]+abs(a-b);
                pq.push({distance[a][b],{a,b}});
            }
        }
    }
    set<pii> p;
    for(int i=0;i<n;i++){
        for(int x : adj1[i]){
            p.insert({min(i,x),max(i,x)});
        }
    }
    set<int> good;
    for(int i=0;i<n;i++){
        for(int x : adj2[i]){
            pii cur = {min(i,x),max(i,x)};
            if(p.find(cur)!=p.end()){
                good.insert(i);
                good.insert(x);
            }
        }
    }
    int ans = inf;
    for(int x : good){
        ans = min(ans,distance[x][x]);
    }
    cout << (ans!=inf ? ans:-1) << "\n";
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
