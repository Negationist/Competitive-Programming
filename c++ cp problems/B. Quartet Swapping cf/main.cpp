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
using ld = long double;

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
        if(l>r) return identity;
        return query(1, 0, n - 1, l, r);
    }
};

void solve(){
    int n;
    cin >> n;
    vi even, odd;
    for(int i=1;i<=n;i++){
        int z;
        cin >> z;
        if(i&1){
            odd.pb(z);
        } else{
            even.pb(z);
        }
    }
    auto add = [&](int a, int b){
        return a+b;
    };
    auto cnt = [&](vi &a){
        Segtree<ll, decltype(add)> tree(add, 0LL, n + 10);
        int res = 0;
        for(int x : a){
            res+=tree.query(x+1,n+9);
            tree.set(x,1LL);
        }
        return res;
    };
    int x = cnt(odd)%2, y = cnt(even)%2;
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    if(x!=y){
        if(n&1){
            int sze = odd.size();
            swap(odd[sze-1],odd[sze-2]);
        } else{
            int sze = even.size();
            swap(even[sze-1],even[sze-2]);
        }
    }
    x = 0; y = 0;
    for(int i=1;i<=n;i++){
        if(i&1){
            cout << odd[x++] << " ";
        } else{
            cout << even[y++] << " ";
        }
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
