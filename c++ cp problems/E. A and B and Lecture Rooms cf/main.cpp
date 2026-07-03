#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
vi sze;
vi par;
struct Tree{
    vector<vector<int>> adj;
    vector<int> depth;
    vector<bool> visited;
    vector<vector<int>> up;
    int LOG;
    int root;
    Tree(int n, int f){
        LOG = 32-__builtin_clz(n);
        up.assign(n,vector<int>(LOG,-1));
        adj.resize(n);
        depth.resize(n);
        visited.assign(n,false);
        root = f;
        depth[root] = 0;
    }
    void push(int a,int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }

    void build(int cur, int parent){
        up[cur][0] = parent;
        for(int i=1;i<LOG;i++){
            if(up[cur][i-1]!=-1) up[cur][i] = up[up[cur][i-1]][i-1];
        }
        for(int x : adj[cur]){
            if(x==parent) continue;
            depth[x] = depth[cur]+1;
            build(x,cur);
        }
    }

    int kthAncestor(int cur, int k){
        if(k>=depth[cur]) return root;
        for(int i=LOG-1;i>=0;i--){
            if(k&(1<<i)){
                cur = up[cur][i];
            }
        }
        return cur;
    }

    int lca(int a, int b){
        if(depth[a]<depth[b]){
            swap(a,b);
        }
        int delta = depth[a]-depth[b];
        a = kthAncestor(a,delta);
        if(a==b){
            return a;
        }
        for(int i=LOG-1;i>=0;i--){
            int l = up[a][i];
            int r = up[b][i];
            if(l!=r){
                a=l;
                b=r;
            }
        }
        return up[a][0];
    }

    int dfs(int cur, int p){
        par[cur] = p;
        sze[cur] = 1;
        for(int x : adj[cur]){
            if(x!=p){
                dfs(x,cur);
                sze[cur]+=sze[x];
            }
        }
        return sze[cur];
    }

    int dist(int a, int b){
        int z = lca(a,b);
        return depth[a]+depth[b]-2*depth[z];
    }
};


void solve(){
    int n;
    cin >> n;
    Tree tree(n,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        tree.push(--a,--b);
    }
    tree.build(0,-1);
    sze.resize(n);
    par.resize(n);
    tree.dfs(0,-1);
    int m;
    cin >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        if(x==y){
            cout << n << "\n";
            continue;
        }
        int dis = tree.dist(x,y);
        if(dis%2==1){
            cout << 0 << "\n";
            continue;
        }
        if(tree.depth[x]<tree.depth[y]){
            swap(x,y);
        }
        int middle = tree.kthAncestor(x,dis/2);
        bool dc = false;
        int upx = tree.kthAncestor(x,dis/2-1);
        int upy = tree.kthAncestor(y,dis/2-1);
        if(!(tree.depth[y]<dis/2-1) && par[upy]==middle){
            dc = true;
        }
        int res;
        if(dc){
            res = n;
            res-=sze[upx];
            res-=sze[upy];
        } else{
            res = sze[middle];
            res-=sze[upx];
        }
        cout << res << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
