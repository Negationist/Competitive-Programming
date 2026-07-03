#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 1e9+7;

int binPowMod(int b, int p, int mod){
    int res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}


int n;
struct Tree{
    vector<vector<int>> adj;
    vector<int> depth;
    vector<bool> visited;
    vector<vector<int>> up;
    vector<int> cnt;
    int LOG;
    int root;
    Tree(int n, int f){
        LOG = 32-__builtin_clz(n);
        up.assign(n,vector<int>(LOG,-1));
        adj.resize(n);
        depth.resize(n);
        visited.assign(n,false);
        cnt.resize(n);
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

    void dfs(int cur, int p){
        cnt[cur] = (p!=-1?cnt[p]:0)+(cur>=n);
        for(int x : adj[cur]){
            if(x!=p){
                dfs(x,cur);
            }
        }
    }

    int dist(int a, int b){
        if(depth[a]<depth[b]){
            swap(a,b);
        }
        int res;
        int z = lca(a,b);
        if(z!=b){
            res = cnt[a]+cnt[b];
            if(z!=root){
                res-=2*cnt[up[z][0]];
            }
            if(z>n){
                --res;
            }
        } else{
            res = cnt[a];
            if(z!=root){
                res-=cnt[up[z][0]];
            }
        }
        return res;
    }
};


void solve(){
    int m;
    cin >> n >> m;
    vector<vi> adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    map<int,int> rep;
    for(int i=0;i<n;i++){
        rep[i] = i;
    }
    vector<bool> visited(n,false);
    vector<int> par(n,-1);
    int inc = n; //fake nodes
    auto dfs = [&](auto self, int x, int p)->void{
        if(visited[x]){
            rep[x] = inc;
            int temp = p;
            while(temp!=x){
                rep[temp] = inc;
                temp = par[temp];
            }
            ++inc;
            return;
        }
        visited[x] = true;
        par[x] = p;
        for(int y : adj[x]){
            if(y!=p && rep[y]<n){
                self(self, y, x);
            }
        }
    };
    dfs(dfs,0,-1);
    Tree tree(inc,rep[0]);
    set<pii> pushed;
    for(int i=0;i<n;i++){
        for(int x :adj[i]){
            if(rep[x]==rep[i]) continue;
            pii cur = {rep[x],rep[i]};
            if(cur.ff<cur.ss){
                swap(cur.ff,cur.ss);
            }
            if(pushed.find(cur)!=pushed.end()) continue;
            pushed.insert(cur);
            tree.push(rep[i],rep[x]);
            //cout << rep[x] << " " << rep[i] << "\n";
        }
    }
    tree.build(rep[0],-1);
    tree.dfs(rep[0],-1);
    /*for(int i=0;i<inc;i++){
        cout << "depth of " << i << " is " << tree.depth[i] << "\n";
    }*/
    int k;
    cin >> k;
    while(k--){
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        if(rep[x]==rep[y]){
            cout << "2\n";
            continue;
        }
        //cout << rep[x] << " " << rep[y] << "\n";
        int num = tree.dist(rep[x],rep[y]);
        cout << binPowMod(2,num,mod) << "\n";
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
