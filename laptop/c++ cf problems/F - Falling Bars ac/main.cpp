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

enum QueryType { ADD, SET, NONE };

struct Tag {
    QueryType type = NONE;
    ll val = 0;
    void apply(const Tag &t) {
        if (t.type == ADD) {
            val += t.val;
            if (type != SET) type = ADD;
        } else if (t.type == SET) {
            type = SET;
            val = t.val;
        }
    }
};

struct Info {
    ll sum = 0, max_val = LLONG_MIN;
    void apply(const Tag &t, int l, int r) {
        if (t.type == SET) {
            sum = t.val * (r - l + 1);
            max_val = t.val;
        } else if (t.type == ADD) {
            sum += t.val * (r - l + 1);
            max_val += t.val;
        }
    }
    friend Info operator+(const Info &a, const Info &b) {
        return {a.sum + b.sum, max(a.max_val, b.max_val)};
    }
};

template<class Info, class Tag>
struct lazySegTree {
    int n;
    vector<Info> tree;
    vector<Tag> lazy;

    void build(int v, int l, int r, vector<Info> &a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    void apply(int v, int l, int r, const Tag &t) {
        tree[v].apply(t, l, r);
        lazy[v].apply(t);
    }

    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, l, m, lazy[v]);
        apply(2 * v + 1, m + 1, r, lazy[v]);
        lazy[v] = Tag();
    }

    void range_update(int v, int l, int r, int ql, int qr, const Tag &t) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(v, l, r, t);
        } else {
            push_down(v, l, r);
            int m = (l + r) / 2;
            range_update(2 * v, l, m, ql, qr, t);
            range_update(2 * v + 1, m + 1, r, ql, qr, t);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    Info range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Info();
        if (ql <= l && r <= qr) return tree[v];
        push_down(v, l, r);
        int m = (l + r) / 2;
        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
    }

    lazySegTree(int n) {
        this->n = n;
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
    }

    lazySegTree(const vector<Info> &a) {
        n = a.size();
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
        build(1, 0, n - 1, a);
    }

    void range_update(int ql, int qr, const Tag &t) {
        range_update(1, 0, n - 1, ql, qr, t);
    }

    Info range_query(int ql, int qr) {
        return range_query(1, 0, n - 1, ql, qr);
    }
};

void solve() {
    int h,w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<tuple<int,int,int>> a(n);
    for(int i=0;i<n;i++){
        int r,c,l;
        cin >> r >> c >> l;
        a[i] = {-r,c,l};
    }
    map<tuple<int,int,int>,int> ans;
    auto b = a;
    sort(b.begin(),b.end());
    lazySegTree<Info,Tag> tree(w+5);
    for(auto [r,c,l] : b){
        int mx = max(tree.range_query(c,c+l-1).max_val,0LL);
        ans[{r,c,l}] = mx+1;
        tree.range_update(c,c+l-1,{SET,mx+1});
    }
    for(int i=0;i<n;i++){
        cout << h-ans[a[i]]+1 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
