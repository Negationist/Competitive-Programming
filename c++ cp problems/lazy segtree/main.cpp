#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll sum, mn, mx;
};

struct LazySegtree {
    int n;
    vector<Node> tree;
    vector<ll> lazy;
    Node combine(const Node &l, const Node &r) {
        return { l.sum + r.sum, min(l.mn, r.mn), max(l.mx, r.mx) };
    }
    void build(const vector<ll>& a) {
        for (int i = 0; i < a.size(); i++) {
            tree[i + n] = { a[i], a[i], a[i] };
        }
        for (int i = a.size(); i < n; i++) {
            tree[i + n] = { 0, LLONG_MAX, LLONG_MIN };
        }
        for (int i = n - 1; i >= 1; i--) {
            tree[i] = combine(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    void apply(int v, int l, int r, ll add) {
        tree[v].sum += add * (r - l + 1);
        tree[v].mn += add;
        tree[v].mx += add;
    }
    void push_down(int v, int l, int r) {
        if (lazy[v] != 0) {
            int m = (l + r) / 2;
            apply(2 * v, l, m, lazy[v]);
            apply(2 * v + 1, m + 1, r, lazy[v]);
            lazy[v] = 0;
        }
    }
    void update(int v, int l, int r, int ql, int qr, ll add) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(v, l, r, add);
            return;
        }
        push_down(v, l, r);
        int m = (l + r) / 2;
        update(2 * v, l, m, ql, qr, add);
        update(2 * v + 1, m + 1, r, ql, qr, add);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    Node query(int v, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return { 0, LLONG_MAX, LLONG_MIN };
        if (ql <= l && r <= qr) return tree[v];
        push_down(v, l, r);
        int m = (l + r) / 2;
        Node left = query(2 * v, l, m, ql, qr);
        Node right = query(2 * v + 1, m + 1, r, ql, qr);
        return combine(left, right);
    }
    LazySegtree(vector<ll>& a) {
        int _n = a.size();
        int log = 31 - __builtin_clz(_n);
        log += (__builtin_popcount(_n) > 1);
        n = 1LL << log;
        tree.resize(2 * n, { 0, LLONG_MAX, LLONG_MIN });
        lazy.assign(n, 0);
        build(a);
    }
    void range_update(int ql, int qr, ll add) {
        update(1, 0, n - 1, ql, qr, add);
    }
    ll range_sum(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr).sum;
    }
    ll range_min(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr).mn;
    }
    ll range_max(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr).mx;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
