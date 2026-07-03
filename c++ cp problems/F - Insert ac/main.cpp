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

template <typename T, typename F>
struct Segtree {
    int n, sze;
    vector<T> tree;
    F merge;
    T identity;

    Segtree(F merge_op, T id, int n) : merge(merge_op), identity(id) {
        sze = 1 << (__lg(n) + ((n & (n - 1)) != 0)); // Round up to power of two
        this->n = sze;
        tree.assign(2 * sze, identity);
    }

    void build(vector<T> &a, int x, int l, int r) {
        if (l == r) {
            if (l < (int)a.size()) tree[x] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, 2 * x, l, m);
        build(a, 2 * x + 1, m + 1, r);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void build(vector<T> &a) {
        build(a, 1, 0, n - 1);
    }

    void set(int x, int l, int r, int i, T v) {
        if (l == r) {
            tree[x] = v;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            set(2 * x, l, m, i, v);
        else
            set(2 * x + 1, m + 1, r, i, v);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void set(int i, T v) {
        set(1, 0, n - 1, i, v);
    }

    T query(int x, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return identity;
        if (ql <= l && r <= qr) return tree[x];
        int m = (l + r) / 2;
        return merge(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve(){
    int n;
    cin >> n;
    vi p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    auto op = [&](int a, int b){
        return a+b;
    };
    Segtree<int,decltype(op)> Tree(op,0,n);
    vi a(n,1);
    vi ans(n);
    Tree.build(a);
    for(int i=n-1;i>=0;i--){
        int target = p[i];
        int node = 1;
        while(node<Tree.n){
            if(Tree.tree[node*2]>=target){
                node = node*2;
            } else{
                target-=Tree.tree[node*2];
                node = node*2+1;
            }
        }
        ans[node-Tree.n] = i+1;
        Tree.set(node-Tree.n,0);
    }
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
