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
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t; // available on 64-bit targets

const int maxB = 18;

template <typename T>
struct Segtree {
    ll n;
    std::vector<T> tree;
    std::function<T(T, T)> merge;
    T identity;
    Segtree(std::function<T(T, T)> merge_op, T id, ll _n)
        : n(_n), merge(merge_op), identity(id) {
            tree.assign(4LL << __lg(n), identity);
        }
    void set(ll x, T v) {
        assert(x<n);
        set(1, 0, n - 1, x, v);
    }
    void add(ll x, T delta) {
        assert(x<n);
        add(1, 0, n - 1, x, delta);
    }
    T query(ll ql, ll qr) const {
        if (qr < ql) return identity;
        return query(1, 0, n - 1, ql, qr);
    }
    void build(const std::vector<T>& data) {
        assert((ll)data.size() <= n);
        build(1, 0, n - 1, data);
    }
    void set(ll p, ll l, ll r, ll i, T v) {
        if (l == r) { tree[p] = v; return; }
        ll m = (l + r) >> 1;
        (i <= m ? set(p << 1, l, m, i, v)
                : set(p << 1 | 1, m + 1, r, i, v));
        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }
    void add(ll p, ll l, ll r, ll i, T delta) {
        if (l == r) {
            tree[p] = merge(tree[p], delta);
            return;
        }
        ll m = (l + r) >> 1;
        (i <= m ? add(p << 1, l, m, i, delta)
                : add(p << 1 | 1, m + 1, r, i, delta));
        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }
    T query(ll p, ll l, ll r, ll ql, ll qr) const {
        if (qr < l || r < ql)   return identity;
        if (ql <= l && r <= qr) return tree[p];
        ll m = (l + r) >> 1;
        return merge(query(p << 1,     l, m, ql, qr),
                     query(p << 1 | 1, m+1, r, ql, qr));
    }
    void build(ll p, ll l, ll r, const std::vector<T>& data) {
        if (l == r) {
            tree[p] = (l<(ll)(data.size())?data[l]:identity); return;
        }
        ll m = (l + r) >> 1;
        build(p << 1, l, m, data);
        build(p << 1 | 1, m + 1, r, data);
        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }
};

void solve(){
    int n,z = 0;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<vi> m(maxB+1,vi(2,0));
    vi cnt(n+1,1);
    cnt[0] = 0;
    Segtree<int> tree([](int a, int b) { return a + b; },0,n+5);
    for(int i=0;i<n;i++){
        int msb = 63 - __builtin_clzll(a[i]);
        for(int j=0;j<maxB;j++){
            if(msb==j){
                m[j][0]+=tree.query(0,(1LL<<msb)-1);
            } else if(msb>j){
                int lo = 0;
                for(int k=maxB;k>j;k--){
                    if((1LL<<k)&a[i]){
                        lo+=(1LL<<k);
                    }
                }
                if((1LL<<j)&a[i]){
                    m[j][0]+=tree.query(lo,lo+(1LL<<j)-1);
                } else{
                    m[j][1]+=tree.query(lo+(1LL<<j),lo+2*(1LL<<j)-1);
                }
            } else{
                m[j][1]+=tree.query((1LL<<j),(1LL<<j)*2-1);
            }
        }
        z+=tree.query(a[i],n);
        tree.set(a[i],1);
    }
    int ans = 1e16;
    for(int i=0;i<n;i++){
        cnt[i]+=z;
        for(int j=0;j<maxB;j++){
            if((1LL<<j)&i){
                cnt[i]+=(m[j][0]-m[j][1]);
            }
        }
        ans = min(ans,cnt[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}