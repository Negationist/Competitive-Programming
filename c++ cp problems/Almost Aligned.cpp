#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const double EPS = 1e-9;

set<double> points;

struct Line {
	mutable double k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(double x) const { return p < x + EPS; }
};

struct LineContainer : multiset<Line, less<>> {
	static constexpr double inf = std::numeric_limits<double>::infinity();

	// Compute intersection point of two lines
	double div(double a, double b) { return a / b; }

	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, false;
		if (abs(x->k - y->k) < EPS) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p + EPS >= y->p;
	}

	void add(double k, double m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p + EPS >= y->p)
			isect(x, erase(y));
	}

	double query(double x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

void add_points(LineContainer &cht){
    for (auto line : cht) {
        if(std::isfinite(line.p) && line.p>=0){
            points.insert(line.p);
        }
    }
}


void solve(){
    int n;
    cin >> n;
    LineContainer xmax,xmin,ymax,ymin;
    while(n--){
        ll x,y,vx,vy;
        cin >> x >> y >> vx >> vy;
        xmax.add(vx,x);
        xmin.add(-vx,-x);
        ymax.add(vy,y);
        ymin.add(-vy,-y);
    }
    add_points(xmax);
    add_points(xmin);
    add_points(ymax);
    add_points(ymin);
    double ans = LineContainer::inf;
    points.insert(0.0);
    for(auto p : points){
        double res = (xmax.query(p)+xmin.query(p))*(ymax.query(p)+ymin.query(p));
        ans = min(res,ans);
    }
    cout << fixed << setprecision(15) << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}