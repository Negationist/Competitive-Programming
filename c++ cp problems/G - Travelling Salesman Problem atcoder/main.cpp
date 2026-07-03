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

ll op(ll a, ll b){
    return a+b;
}

template <typename T>
struct BoundedSegtree {
    ll L, R, n;
    std::vector<T> tree;
    std::function<T(T, T)> merge;
    T identity;
    BoundedSegtree(std::function<T(T, T)> merge_op, T id, ll left, ll right)
        : L(left), R(right), n(right - left + 1), merge(merge_op), identity(id) {
            assert(L<=R);
            tree.assign(4 * n , identity);
        }
    ll idx(ll x) const { return x - L; }
    void set(ll x, T v) {
        assert(L<=x && x<=R);
        set(1, 0, n - 1, idx(x), v);
    }
    void add(ll x, T delta) {
        assert(L <= x && x <= R);
        add(1, 0, n - 1, idx(x), delta);
    }
    T query(ll ql, ll qr) const {
        if (qr < ql) return identity;
        return query(1, 0, n - 1, idx(ql), idx(qr));
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

struct slope_trick {
    using Seg = BoundedSegtree<ll>;
    ll m = 0, b = 0;
    ll L = 0, R = 0;
    std::map<ll, ll> points;
    bool use_history = false;
    bool use_tree    = false;
    bool found = false;
    std::vector<std::tuple<ll, ll, ll>> changes;
    std::unique_ptr<Seg> tree;
    slope_trick(bool enable_history = false,
                bool enable_tree    = false,
                ll  m_init          = 0,
                ll  b_init          = 0,
                ll  left_bound      = -1,
                ll  right_bound     = 1)
        : m(m_init), b(b_init), L(left_bound), R(right_bound),
          use_history(enable_history), use_tree(enable_tree)
    {
        if (use_tree) {
            tree = std::make_unique<Seg>(op, 0LL, L, R);
        }
    }
    void log_change(ll type, ll x, ll d) {
        if (use_history) changes.emplace_back(type, x, d);
    }
    ll timestamp(){
        return (ll)(changes.size());
    }
    ll slope_at(ll x){ //not that at turning points the LOWER slope is considered
        if(!use_tree) return -1;
        if(x>R) return m;
        else if(L<=x && x<=R){
            return m - (tree->query(x,R));
        }
        else{
            return m - (tree->query(L,R));
        }
    }
    void rollback(ll idx){
        while((ll)changes.size()>idx){
            auto [type, x, d] = changes.back();
            changes.pop_back();
            if(type == 1){
                m -= x;
            } else if(type == 2){
                b -= x;
            } else{
                points[x]-=d;
                if (!points[x]) points.erase(x);
                if (use_tree){
                    tree->set(x, points.count(x) ? points[x] : 0);
                }
            }
        }
    }
    void add_slope(ll x, ll delta) {
        if (!delta) return;
        points[x] += delta;
        if (!points[x]) points.erase(x);
        if (use_tree) tree->set(x, points.count(x) ? points[x] : 0);
        if (use_history) log_change(3, x, delta);
    }
    bool set_max(ll mx) { //check this
        ll old_m = m, old_b = b;
        auto it = points.rbegin();
        vii operations;
        while (m > mx && it != points.rend()) {
            ll x = it->ff, cnt = it->ss;
            ++it;
            ll y = m * x + b;
            ll take = std::min(cnt, m - mx);
            operations.pb({x,-take});
            m -= take;
            b = y - m * x;
        }
        for(auto [x,y] : operations){
            add_slope(x,y);
        }
        log_change(1, m - old_m, 0);
        log_change(2, b - old_b, 0);
        return (m <= mx);
    }
    //note that there is no maximum in a convex function
    std::pair<ll,ll> get_min(){
        ll min_slope = slope_at(L);
        if(min_slope>0 || m<0) return {-1,-1};
        if(!points.size()) return {0,b};
        auto it = points.rbegin();
        int cur = m, x = it->ff, y = m*x+b;
        while(cur>0 && it != points.rend()){
            y = y + cur*((it->ff)-x);
            x = it->ff;
            cur-=(it->ss);
            ++it;
        }
        return {x,y};
    }
    bool set_min(ll mn) { //check this
        if (m < mn) return false;
        if(use_tree){
            ll delta_old = m - slope_at(L), delta_new = m - mn;
            ll pool = delta_old - delta_new;
            vii operations;
            for (auto it = points.begin(); it != points.end() && pool>0;) {
                ll x = it->ff, cnt = it->ss;
                ++it;
                ll take = std::min(cnt, pool);
                operations.pb({x,-take});
                pool-=take;
            }
            for(auto [x,y] : operations){
                add_slope(x,y);
            }
        } else{
            ll cur = m;
            vii operations;
            for (auto it = points.rbegin(); it != points.rend();) {
                ll x = it->ff, cnt = it->ss;
                ++it;
                ll take = std::max(cnt - (cur - mn), 0LL);
                operations.pb({x,-take});
                cur -= (points[x]-take);
            }
            for(auto [x,y] : operations){
                add_slope(x,y);
            }
        }
        return true;
    }
    ll query_right(int x){ //find the rightmost point such that the slope is <=x
        int lo = L, hi = R;
        found = false;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(slope_at(mid)<=x){
                found = true;
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        return hi;
    }
    ll query_left(int x){ //find the leftmost point such that the slope is >=x
        int lo = L, hi = R;
        found = false;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(slope_at(mid)+(points.count(mid)?points[mid]:0)>=x){ //bigger range this way
                found = true;
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        return lo;
    }
    slope_trick& operator+=(const slope_trick& o) {
        m += o.m; b += o.b;
        log_change(1, o.m, 0); log_change(2, o.b, 0);
        for (auto [x, d] : o.points) add_slope(x, d);
        return *this;
    }
    slope_trick operator+(const slope_trick& o) const {
        slope_trick res(use_history || o.use_history,
                        use_tree    || o.use_tree,
                        m + o.m, b + o.b,
                        std::min(L, o.L), std::max(R, o.R));
        for (auto [x, d] : points) {
            res.add_slope(x, d);
        }
        for (auto [x, d] : o.points) {
            res.add_slope(x, d);
        }
        return res;
    }
    static slope_trick abs_func(ll slope, ll x_intercept) {
        slope_trick s(false, false, slope, -x_intercept*slope, x_intercept - 1, x_intercept + 1);
        s.points[x_intercept] = 2 * slope;
        return s;
    }
};

void solve(){
    int n,c,d;
    cin >> n >> c >> d;
    vi f(n+1),x(n+1);
    for(int i=1;i<=n;i++){
        cin >> x[i];
    }
    slope_trick func(true,true,0,0,-1e5-5,1e5+5);
    func+=slope_trick::abs_func(2*c,0);
    f[0] = func.timestamp();
    func.set_max(c);
    func.set_min(-c);
    for(int i=1;i<=n;i++){
        func+=slope_trick::abs_func(d,x[i]);
        f[i] = func.timestamp();
        func.set_max(c);
        func.set_min(-c);
    }
    pii ans = func.get_min();
    cout << ans.ss << "\n";
    vi out;
    for(int i=n;i>=1;i--){
        out.pb(ans.ff);
        func.rollback(f[i-1]);
        int left = func.query_left(-c), right = func.query_right(c);
        if(ans.ff<left){
            ans.ff = left;
        } else if(ans.ff>right){
            ans.ff = right;
        }
    }
    reverse(out.begin(),out.end());
    for(int x : out){
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
