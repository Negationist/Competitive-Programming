#include <bits/stdc++.h>
#define int long long
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

struct Tag { //only range updates here
    ll a = 0;
    void apply(const Tag &t) {
        a+=t.a;
    }
};

struct Info {
    ll min_val = 0;
    void apply(const Tag &t, int l, int r) {
        min_val = min_val + t.a;
        
    }
    friend Info operator+(const Info &a, const Info &b) {
        return {min(a.min_val, b.min_val)};
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

void solve(){
    int n; cin >> n;
    vi a(n);
    int mx = -1;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        mx = max(mx, a[i]/2 + 10);
    }
    lazySegTree<Info, Tag> tree(mx);
    lazySegTree<Info, Tag> relax_tree(mx);
    int ans = 0, r_tree_ptr = 0; //contains the biggest number that cannot be made, i.e the answer - 1
    set<int> queue;
    for(int i=0;i<n;i++){
        int res = (a[i] - 1)/2;
        tree.range_update(0, res, {1});
        relax_tree.range_update(0, res, {1});
        queue.insert(a[i]);
        while(true){
            Info query = tree.range_query(0,mx-1);
            //cout << query.min_val << "!!\n";
            if(query.min_val >= 0){
                ans++;
                tree.range_update(0, ans-1, {-1});
            } else{
                
                break;
            }
        }
        cout << ans-1 << " ";
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