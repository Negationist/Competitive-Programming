#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define tiii tuple<int,int,int>
#define print(x) cout << (x) << "\n"
using namespace std;

static const int INF = 1e12; // bigger "infinity" than 1e6

struct dsu {
    vector<int> parent, cnt;
    dsu(int n){
        parent.resize(n);
        cnt.assign(n,1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int _find(int i){
        if(parent[i] != i){
            parent[i] = _find(parent[i]);
        }
        return parent[i];
    }
    bool unite(int a,int b){
        a = _find(a);
        b = _find(b);
        if(a == b) return false;
        if(cnt[a] < cnt[b]) swap(a,b);
        parent[b] = a;
        cnt[a]+=cnt[b];
        return true;
    }
};

void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<tiii> edges;    // will store (w,u,v)
    edges.reserve(m);
    vector<vector<int>> adj(n);

    // Read edges
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges.push_back({w, a, b});
        // For BFS later (cost=1 edges in the original sense)
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [&](auto &A, auto &B){
             return get<0>(A) < get<0>(B);
         });

    // Build MST via DSU
    dsu d(n);
    // 'useful' will store the MST edges in sorted order
    // We'll make it size n (index 0 unused, then edges 1..(n-1)).
    // If the graph is connected, MST has (n-1) edges.
    // Otherwise, 'useful' will have fewer, so be careful with queries.
    vector<tiii> useful;
    useful.reserve(n);
    useful.push_back({0, -1, -1}); // dummy at index 0

    vector<int> weights; // store MST-edge weights in the same order
    weights.reserve(n);
    weights.push_back(0); // dummy

    for(auto &e : edges){
        auto &[ww, uu, vv] = e;
        if(d.unite(uu, vv)){
            useful.push_back({ww, uu, vv});
            weights.push_back(ww);
            if((int)useful.size() == n) break;
            // We only need up to n-1 edges for MST
        }
    }

    // 3D array dp: dp[k][i][j] = shortest path under "k MST edges are flipped to cost=0"
    static int dp[505][505][505];
    // but we will use dimension n for indexing: dp[n][n][n].
    // We have up to n-1 MST edges. So k in [0..n-1].

    // 1) Initialize dp[..][..][0]:
    //    i.e. if no MST edges are flipped => all edges cost=1 => do BFS from each node.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[0][i][j] = INF;
        }
    }

    // BFS for each i to fill dp[0][i][j]
    for(int start=0; start<n; start++){
        queue<int> qq;
        vector<int> dist(n, INF);
        dist[start] = 0;
        qq.push(start);
        while(!qq.empty()){
            int u = qq.front();
            qq.pop();
            for(int v: adj[u]){
                if(dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    qq.push(v);
                }
            }
        }
        // Store BFS distances
        for(int j=0;j<n;j++){
            dp[0][start][j] = dist[j];
        }
    }

    // 2) For k = 1..(n-1), flip the k-th MST edge to cost=0
    //    (k-th MST edge = useful[k], a 1-based indexing in 'useful')
    //    Then do dp update: dp[k][i][j] = min( dp[k-1][i][j],
    //                                          dp[k-1][i][a]+dp[k-1][b][j],
    //                                          dp[k-1][i][b]+dp[k-1][a][j] )
    int mstEdgesCount = (int)useful.size() - 1;
    // (if the graph is connected, this is n-1; else fewer)
    for(int k=1; k<=mstEdgesCount; k++){
        auto [w, x, y] = useful[k];
        // x,y is the k-th MST edge
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[k][i][j] = dp[k-1][i][j];
                int alt1 = dp[k-1][i][x] + dp[k-1][y][j];
                int alt2 = dp[k-1][i][y] + dp[k-1][x][j];
                dp[k][i][j] = min({dp[k][i][j], alt1, alt2});
            }
        }
    }

    // 3) Process queries
    while(q--){
        int a,b,k0;
        cin >> a >> b >> k0;
        a--; b--;

        // We'll do a binary search over how many MST edges we "flip"
        // i.e. search k in [0..mstEdgesCount]
        // If dp[k][a][b] < k0 => we can try smaller k
        // else bigger k

        // If the graph wasn't fully connected, watch out for range.
        int L = 0;
        int R = mstEdgesCount;
        int ans = -1;
        while(L <= R){
            int mid = (L+R)/2;
            if(dp[mid][a][b] < k0){
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        if(ans == -1){
            // means even with flipping 0 MST edges, dp[0][a][b] >= k0
            // so no path with cost < k0
            // For the old code, it simply expects some result,
            // or prints weights[l]. But l ends up out of range.
            // We'll do something consistent:
            cout << weights[0] << "\n";
            // or -1 if you want to denote "no valid answer"
        } else {
            // We needed to flip 'ans' edges
            // The old code prints weights[l].
            // 'weights[k]' is the MST edge weight at index k.
            // For ans=0 => weights[0] is dummy (0).
            // Typically the old code did: cout << weights[l] << "\n";
            cout << weights[ans] << "\n";
        }
    }
    cout << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
