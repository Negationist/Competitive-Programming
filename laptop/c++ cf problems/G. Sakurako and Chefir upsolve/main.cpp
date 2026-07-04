#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

struct Tree{
    vector<vector<int>> adj;
    vector<int> depth;
    vector<bool> visited;
    //just for this
    vector<int> dia;
    vector<vector<int>> up;
    vii ends;
    int LOG;
    //just for this
    int root;
    Tree(int n, int f){
        LOG = 32-__builtin_clz(n);
        up.assign(n,vector<int>(LOG,-1));
        adj.resize(n);
        depth.resize(n);
        visited.assign(n,false);
        //just for this
        dia.resize(n);
        ends.resize(n);
        //just for this
        root = f;
        depth[root] = 0;
    }
    void push(int a,int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }

    void buildKth(int cur, int parent){
        up[cur][0] = parent;
        for(int i=1;i<LOG;i++){
            if(up[cur][i-1]!=-1) up[cur][i] = up[up[cur][i-1]][i-1];
        }
        for(int x : adj[cur]){
            if(x==parent) continue;
            buildKth(x,cur);
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

    int dfs(int cur, int parent){
        int mx1=0,mx2=0,f=cur,s=cur,in=-1;
        for(int x : adj[cur]){
            if(x==parent) continue;
            depth[x] = depth[cur]+1;
            int dMax = 1 + dfs(x,cur);
            if(in==-1 || dia[x]>dia[in]) in=x;
            if(dMax>mx1){
                mx2 = mx1;
                s = f;
                mx1 = dMax;
                f = ends[x].ff;
            } else if(dMax>mx2){
                mx2 = dMax;
                s = ends[x].ff;
            }
        }
        if(in==-1 || mx1+mx2>dia[in]){
            dia[cur] = mx1+mx2;
            ends[cur].ff = f;
            ends[cur].ss = s;
        } else{
            dia[cur] = dia[in];
            ends[cur].ff = ends[in].ff;
            ends[cur].ss = ends[in].ss;
        }
        return mx1;
    }

    int dist(int a, int b){
        int z = lca(a,b);
        return depth[a]+depth[b]-2*depth[z];
    }
};

void solve(){
    int n;
    cin >> n;
    Tree tree = Tree(n,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        tree.push(a,b);
    }
    int q;
    cin >> q;
    tree.dfs(0,-1);
    tree.buildKth(0,-1);
    while(q--){
        int v,k;
        cin >> v >> k;
        v--;
        int anc = tree.kthAncestor(v,k);
        int x = tree.ends[anc].ff;
        int y = tree.ends[anc].ss;
        int ans = max(tree.dist(v,x),tree.dist(v,y));
        cout << ans << " ";
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
