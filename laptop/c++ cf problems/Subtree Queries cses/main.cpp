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

template <typename T, T (*op)(T, T), T identity>
struct segTree {
    vector<T> tree;
    int n;

    segTree(vector<T>& a) {
        int _n = a.size();
        int log = 31 - __builtin_clz(_n);
        log += (__builtin_popcount(_n) > 1);
        n = 1LL << log;
        int num = n << 1LL;
        tree.assign(num, identity);
        for (int i = 0; i < a.size(); i++) {
            tree[i + n] = a[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            tree[i] = op(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    T query(int a, int b) {
        T res = identity;
        a += n; b += n;
        while (a <= b) {
            if (a & 1) res = op(res, tree[a++]);
            if (!(b & 1)) res = op(res, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return res;
    }

    void update(int i, T x) {
        int index = i + n;
        tree[index] = x;
        while (index > 1) {
            index >>= 1;
            tree[index] = op(tree[index * 2], tree[index * 2 + 1]);
        }
    }
};

int range_sum(int a, int b) {
    return a + b;
}

int range_min(int a, int b) {
    return min(a, b);
}

int range_max(int a, int b) {
    return max(a, b);
}

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vii id(n);
    int cnt = -1;
    auto dfs = [&](auto self, int x, int p)->void{
        ++cnt;
        id[x].ff = cnt;
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
            }
        }
        id[x].ss = cnt;
    };
    dfs(dfs,0,-1);
    vi val(n);
    for(int i=0;i<n;i++){
        val[id[i].ff] = a[i];
    }
    segTree<int,range_sum,0LL> tree(val);
    while(q--){
        int z;
        cin >> z;
        if(z==1){
            int s,x;
            cin >> s >> x;
            --s;
            int pos = id[s].ff;
            tree.update(pos,x);
        } else{
            int s;
            cin >> s;
            --s;
            cout << tree.query(id[s].ff,id[s].ss) << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
