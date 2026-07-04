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

int ask(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

void solve(){
    int n; cin >> n;
    vi num(n);
    for(int i=0;i<n;i++){
        num[i] = ask(1,i+1);
    }
    vi a(n);
    auto op = [&](int a, int b){
        return a+b;
    };
    auto lis = [&](vi &a){
        vi dp;
        int len = a.size();
        for(int i=0;i<len;i++){
            int pos = upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
            if(pos==dp.size()){
                dp.pb(a[i]);
            } else{
                dp[pos] = a[i];
            }
        }
        return (int)dp.size();
    };
    Segtree<int> tree(op,0,n);
    for(int i=0;i<n;i++){
        tree.set(i,1);
    }
    for(int i=n-1;i>=1;i--){
        int lo = 0, hi = n-1, diff = num[i]-num[i-1]+1; //find the highest number where there are at least diff+1 things greater or equal to 
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(tree.query(mid,n-1)>=diff){
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        a[i] = hi;
        tree.set(hi,0);
    }
    for(int i=0;i<n;i++){
        if(tree.query(0,i)){
            a[0] = i;
            break;
        }
    }
    cout << "! " << lis(a) << "\n";
    cout.flush();
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}