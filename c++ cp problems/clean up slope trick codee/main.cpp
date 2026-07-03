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

//author: Negationist (Jacob Ezieme)
//date: 5/31/2025
//description: data structure with the ability to store, piecewise, linear, convex functions
//status: moderately tested, all function were used in an accepted submission to "G - Travelling Salesman Problem" in AtCoder Beginner Contest 406, link: "https://atcoder.jp/contests/abc406/tasks/abc406_g"

template <typename T>
struct BoundedSegtree {
    ll L, R, n;
    std::vector<T> tree;
    std::function<T(T, T)> merge; //merge function, you need to provide it
    T identity;
    BoundedSegtree(std::function<T(T, T)> merge_op, T id, ll left, ll right)
        : L(left), R(right), n(right - left + 1), merge(merge_op), identity(id) {
            assert(L <= R);
            tree.assign(4 << std::__lg(n), identity);
        }
    ll idx(ll x) const { return x - L; }
    void set(ll x, T v) {
        assert(L <= x && x <= R);
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
        if (l == r) {
            tree[p] = v;
            return;
        }
        ll m = (l + r) >> 1;
        if (i <= m) {
            set(p << 1, l, m, i, v);
        } else {
            set(p << 1 | 1, m + 1, r, i, v);
        }
        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }
    void add(ll p, ll l, ll r, ll i, T delta) {
        if (l == r) {
            tree[p] = merge(tree[p], delta);
            return;
        }
        ll m = (l + r) >> 1;
        if (i <= m) {
            add(p << 1, l, m, i, delta);
        } else {
            add(p << 1 | 1, m + 1, r, i, delta);
        }
        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }
    T query(ll p, ll l, ll r, ll ql, ll qr) const {
        if (qr < l || r < ql) return identity;
        if (ql <= l && r <= qr) return tree[p];
        ll m = (l + r) >> 1;
        return merge(
            query(p << 1,     l,    m,    ql, qr),
            query(p << 1 | 1, m + 1, r,    ql, qr)
        );
    }
    void build(ll p, ll l, ll r, const std::vector<T>& data) {
        if (l == r) {
            tree[p] = (l < (ll)data.size() ? data[l] : identity);
            return;
        }
        ll m = (l + r) >> 1;
        build(p << 1,     l,    m,     data);
        build(p << 1 | 1, m + 1, r,     data);
        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }
};

struct slope_trick { //please look at the implementation, do not take the complexities at face value, they are often worse than average case
    using Seg = BoundedSegtree<ll>;
    ll m = 0, b = 0; //slope and y intercept of the right side function
    ll L = 0, R = 0; //leftmost and rightmost points that could have a change in slope
    std::map<ll, ll> points; //slope delta at each point in [L,R]
    bool use_history = false; //if true, you will log all your changes into the "changes" vector
    bool use_tree = false; //if true, you can find the slope at any point in O(logn)
    bool found = false; //if the last query found something valid, this is true, else it is false, see the query function for more details
    std::vector<std::tuple<ll, ll, ll>> changes; //holds the changes, format is {type,y,z}, see the implementation in the rollback function to understand better
    std::unique_ptr<Seg> tree; //segment tree for point slope queries

    slope_trick(bool enable_history = false, //default parameters, since you could quickly mle if you are not careful, by default, history and segment tree queries are turned off
                bool enable_tree    = false,
                ll   m_init         = 0,
                ll   b_init         = 0,
                ll   left_bound     = -1,
                ll   right_bound    = 1)
        : m(m_init), b(b_init), L(left_bound), R(right_bound),
          use_history(enable_history), use_tree(enable_tree)
    {
        if (use_tree) {
            tree = std::make_unique<Seg>(op, 0LL, L, R);
        }
    }

    void log_change(ll type, ll x, ll d) { //logs changes that can be reversed later
        if (use_history) changes.emplace_back(type, x, d);
    }

    ll timestamp() { //returns the size of the changes vector, which is useful for rolling back the function to a specific point, see the rollback function
        return (ll)changes.size();
    }

    ll slope_at(ll x) { //slope at point x,  NOTE THAT at turning points the LOWER slope is considered. Be careful, using this function without a tree is VERY slow
        if (!use_tree){ //O(|points|log(|points|))
            ll cur = m;
            auto it = points.rbegin();
            while(it!=points.rend() && it->ff >= x){
                cur-=(it->ss);
                ++it;
            }
            return cur;
        } else{
            if (x > R) { //O(log(R-L))
                return m;
            } else if (L <= x && x <= R) {
                return m - tree->query(x, R);
            } else {
                return m - tree->query(L, R);
            }
        }
    }

    void rollback(ll idx) { //rolls the tree back to the last time when the the number of changes was idx, if it possible, O(|changes|*log(max(R-L, |points|))
        while ((ll)changes.size() > idx) {
            auto [type, x, d] = changes.back();
            changes.pop_back();
            if (type == 1) {
                m -= x;
            } else if (type == 2) {
                b -= x;
            } else {
                points[x] -= d;
                if (!points[x]) points.erase(x);
                if (use_tree) {
                    tree->set(x, points.count(x) ? points[x] : 0); //add
                }
            }
        }
    }

    void add_slope(ll x, ll delta) { //add slope delta to a point, and logs the change if logs are activated, O(log(max(R-L, |points|))
        if (!delta) return;
        points[x] += delta;
        if (!points[x]) points.erase(x);
        if (use_tree) {
            tree->set(x, points.count(x) ? points[x] : 0);
        }
        if (use_history) {
            log_change(3, x, delta);
        }
    }

    bool set_max(ll mx) { //sets the maximum slope of the function to mx, returns true if successful, else it returns false, O(|points|*log(max(R-L, |points|)), often there is some global bound on the complexity this function adds, you can only remove things as many times as you add them
        ll old_m = m, old_b = b;
        auto it = points.rbegin();
        std::vector<std::pair<ll, ll>> operations;
        while (m > mx && it != points.rend()) {
            ll x   = it->first;
            ll cnt = it->second;
            ++it;
            ll y    = m * x + b;
            ll take = std::min(cnt, m - mx);
            operations.push_back({ x, -take });
            m -= take;
            b = y - m * x;
        }
        for (auto [x, y] : operations) {
            add_slope(x, y);
        }
        log_change(1, m - old_m, 0);
        log_change(2, b - old_b, 0);
        return (m <= mx);
    }

    // NOTE THAT there is no maximum in a convex function unless it is flat, note that in a problem with concave functions, you can simply mirror the functions about the x axis
    std::pair<ll, ll> get_min() { //returns the right most point where the function is minimum or {0,b} where there is no slope delta
        ll min_slope = slope_at(L);
        if (min_slope > 0 || m < 0) {
            return std::make_pair(-1LL, -1LL);
        }
        if (!points.size()) {
            return std::make_pair(0LL, b);
        }
        auto it = points.rbegin();
        ll cur = m;
        ll x   = it->first;
        ll y   = m * x + b;
        while (cur > 0 && it != points.rend()) {
            y = y + cur * ((it->first) - x);
            x = it->first;
            cur -= it->second;
            ++it;
        }
        return std::make_pair(x, y);
    }

    bool set_min(ll mn) { //sets the minimum slope of the function to mn, returns true if successful, else it returns false, O(|points|*log(max(R-L, |points|)), often there is some global bound on the complexity this function adds, you can only remove things as many times as you add them
        if (m < mn) return false;
        if (use_tree) {
            ll delta_old = m - slope_at(L);
            ll delta_new = m - mn;
            ll pool      = delta_old - delta_new;
            std::vector<std::pair<ll, ll>> operations;
            for (auto it = points.begin(); it != points.end() && pool > 0;) {
                ll x   = it->first;
                ll cnt = it->second;
                ++it;
                ll take = std::min(cnt, pool);
                operations.push_back({ x, -take });
                pool -= take;
            }
            for (auto [x, y] : operations) {
                add_slope(x, y);
            }
        } else {
            ll cur = m;
            std::vector<std::pair<ll, ll>> operations;
            for (auto it = points.rbegin(); it != points.rend();) {
                ll x   = it->first;
                ll cnt = it->second;
                ++it;
                ll take = std::max(cnt - (cur - mn), 0LL);
                operations.push_back({ x, -take });
                cur -= (points[x] - take);
            }
            for (auto [x, y] : operations) {
                add_slope(x, y);
            }
        }
        return true;
    }

    ll query_right(ll x) { // find the rightmost point such that the slope is <= x, note that at a turning point, if the slope on the left is acceptable, it will be accepted, with tree: O(log(L-R)*log(L-R)), without tree: O(log(L-R)*|points|)
        ll lo = L, hi = R;
        found = false;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (slope_at(mid) <= x) {
                found = true;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }

    ll query_left(ll x) { // find the leftmost point such that the slope is >= x, note that at a turning point, if the slope on the right is acceptable, it will be accepted, with tree: O(log(L-R)*log(L-R)), without tree: O(log(L-R)*|points|)
        ll lo = L, hi = R;
        found = false;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (slope_at(mid) + (points.count(mid) ? points[mid] : 0) >= x) {
                found = true;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    slope_trick& operator+=(const slope_trick& o) {
        m += o.m;
        b += o.b;
        log_change(1, o.m, 0);
        log_change(2, o.b, 0);
        for (auto [x, d] : o.points) {
            add_slope(x, d);
        }
        return *this;
    }

    slope_trick operator+(const slope_trick& o) const {
        slope_trick res(
            use_history || o.use_history,
            use_tree    || o.use_tree,
            m + o.m,
            b + o.b,
            std::min(L, o.L),
            std::max(R, o.R)
        );
        for (auto [x, d] : points) {
            res.add_slope(x, d);
        }
        for (auto [x, d] : o.points) {
            res.add_slope(x, d);
        }
        return res;
    }

    static slope_trick abs_func(ll slope, ll c) { //return the function representing slope|x-c|
        slope_trick s(
            false,
            false,
            slope,
            -c * slope,
            c - 1,
            c + 1
        );
        s.points[c] = 2 * slope;
        return s;
    }
};

void solve() {
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
