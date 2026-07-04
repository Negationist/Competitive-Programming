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
    Info(){

    };
    void set(int a){

    }
};

Info merge(Info &l, Info &r){
    Info res{};

    return res;
}

template <typename Info, typename F>
struct Segtree {
    int n;
    vector<Info> tree;
    Segtree(int n) : n(n) {
        tree.assign(4 << __lg(n), Info());
    }
    void build(vector<F> &a, int x, int l, int r) {
        if (l == r) {
            if (l < (int)a.size()){
                tree[x].set(a[l]);
            }
            return;
        }
        int m = (l + r) / 2;
        build(a, 2 * x, l, m);
        build(a, 2 * x + 1, m + 1, r);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }
    void build(vector<F> &a) {
        build(a, 1, 0, n - 1);
    }
    void set(int x, int l, int r, int i, F v) {
        if (l == r) {
            tree[x].set(v);
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            set(2 * x, l, m, i, v);
        else
            set(2 * x + 1, m + 1, r, i, v);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }
    void set(int i, F v) {
        set(1, 0, n - 1, i, v);
    }
    Info query(int x, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) return tree[x];
        int m = (l + r) / 2;
        return merge(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
    }
    Info query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve(){

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
