#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

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
    ll sum = 0, max_val = 0;
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
        tree.assign(4 * n, Info());
        lazy.assign(4 * n, Tag());
    }

    lazySegTree(const vector<Info> &a) {
        n = a.size();
        tree.assign(4 * n, Info());
        lazy.assign(4 * n, Tag());
        build(1, 0, n - 1, a);
    }

    void range_update(int ql, int qr, const Tag &t) {
        range_update(1, 0, n - 1, ql, qr, t);
    }

    Info range_query(int ql, int qr) {
        return range_query(1, 0, n - 1, ql, qr);
    }
};

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n),b(n),c(n-1);
    for(int i=0;i<n;i++) cin >> a[i];
    int sumb = 0;
    for(int i=0;i<n;i++){
        cin >> b[i];
        sumb+=b[i];
    }
    for(int i=0;i<n-1;i++) cin >> c[i];
    lazySegTree<Info,Tag> tree(n);
    for(int i=0;i<n;i++){
        tree.range_update(i,n-1,{ADD,b[i]-a[i]});
    }
    while(q--){
        int p,x,y,z;
        cin >> p >> x >> y >> z;
        --p;
        tree.range_update(p,n-1,{ADD,a[p]-b[p]});
        sumb+=(y-b[p]);
        a[p] = x; b[p] = y;
        tree.range_update(p,n-1,{ADD,b[p]-a[p]});
        Info res = tree.range_query(0,n-1);
        int temp = res.max_val;
        temp = max(temp,0LL);
        cout << sumb-temp << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
