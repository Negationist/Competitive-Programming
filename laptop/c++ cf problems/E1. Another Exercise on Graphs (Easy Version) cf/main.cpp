#include <bits/stdc++.h>
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define tii tuple<int,int,int>
#define each(a, x) for(auto &&a : x)

using namespace std;
const int maxN = 400;
const int inf = 1e4;
pair<int,short> ans[maxN][maxN][maxN];
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
    vector<vii> adj(n);
    vector<tii> all;
    set<int> weights;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        all.pb({w,--a,--b});
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    sort(all.begin(),all.end());
    dsu tree(n);
    for(int i=0;i<m;i++){
        int w = get<0>(all[i]);
        int a = get<1>(all[i]);
        int b = get<2>(all[i]);
        if(tree.unite(a,b)){
            weights.insert(w);
        }
    }
    short anscnt[maxN][maxN] = {};
    for(int z : weights){
        for(int i=0;i<n;i++){
            int distance[n];
            memset(distance, -1, sizeof(distance));
            distance[i] = 0;
            deque<int> dq;
            dq.push_front(i);
            while(dq.size()){
                int x = dq.front();
                dq.pop_front();
                for(auto y : adj[x]){
                    if(y.ss > z){
                        if(distance[y.ff]==-1 || distance[x]+1 < distance[y.ff]){
                            distance[y.ff] = distance[x]+1;
                            dq.push_back(y.ff);
                        }
                    } else{
                        if(distance[y.ff]==-1 || distance[x] < distance[y.ff]){
                            distance[y.ff] = distance[x];
                            dq.push_front(y.ff);
                        }
                    }
                }
            }
            for(int j=i+1;j<n;j++){
                ans[i][j][anscnt[i][j]++] = {z,distance[j]};
            }
        }
    }
    while(q--){
        int a,b,k;
        cin >> a >> b >> k;
        --a;--b;
        if(a>b) swap(a,b);
        int l = 0, r = anscnt[a][b]-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(ans[a][b][mid].ss<k){
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        cout << ans[a][b][l].ff << " ";
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
