#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

struct Info{
    int val[3];
    Info combine
};

template <typename T, typename F>
struct Segtree {
    int n;
    vector<T> tree;
    F merge;
    T identity;

    Segtree(F merge_op, T id, int n) : merge(merge_op), identity(id), n(n) {
        tree.assign(4 << __lg(n), identity);
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

    voCid set(int i, T v) {
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
    cout << "done!\n";
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