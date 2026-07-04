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
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
const int inf = 1e6;
struct dsu{
    vector<int> parent;
    vector<int> cnt;
    dsu(int n){
        parent.resize(n);
        cnt.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int _find(int i){
        if(i!=parent[i]){
            parent[i] = _find(parent[i]);
        }
        return parent[i];
    }
    bool unite(int a, int b){
        int x = _find(a);
        int y = _find(b);
        if(x==y) return false;
        if(cnt[x]<cnt[y]){
            swap(x,y);
        }
        parent[y] = x;
        cnt[x]+=cnt[y];
        return true;
    }
};

void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<tiii> edges;
    vector<vi> adj(n);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[--a].pb(--b);
        adj[b].pb(a);
        edges.pb({w,a,b});
    }
    sort(edges.begin(),edges.end());
    vector<tiii> useful;
    useful.push_back({0, -1, -1});
    vi weights;
    weights.pb(0);
    dsu tree(n);
    for(auto &[w,a,b] : edges){
        if(tree.unite(a,b)){
            useful.pb({w,a,b});
            weights.pb(w);
        }
    }
    vector<vector<vi>> dp(n,vector<vi>(n,vi(n)));
    for(int i=0;i<n;i++){
        dp[i][i][0] = 0;
        deque<int> dq;
        vi distance(n,inf);
        distance[i] = 0;
        dq.push_front(i);
        while(dq.size()){
            int x = dq.front();
            dq.pop_front();
            for(int y : adj[x]){
                if(distance[y]==inf){
                    distance[y] = distance[x]+1;
                    dp[i][y][0] = distance[y];
                    dq.push_back(y);
                }
            }
        }
    }
    int num = useful.size();
    for(int k=1;k<num;k++){
        int a = get<1>(useful[k]);
        int b = get<2>(useful[k]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int res1 = dp[i][a][k-1]+dp[b][j][k-1];
                int res2 = dp[i][b][k-1]+dp[a][j][k-1];
                dp[i][j][k] = min({dp[i][j][k-1],res1,res2});
            }
        }
    }
    while(q--){
        int a,b,k;
        cin >> a >> b >>k;
        --a;--b;
        int l = 0, r = num;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(dp[a][b][mid] < k){
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        cout << weights[l] << " ";
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
