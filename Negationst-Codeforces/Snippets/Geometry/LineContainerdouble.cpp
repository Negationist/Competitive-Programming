/**
 * Author: Simon Lindholm (modified for doubles)
 * Description: Line container for maximum queries using doubles.
 * Supports adding lines of the form y = kx + m, and querying the maximum y-value at a given x.
 * Time: O(log N) per add/query
 */

// #pragma once
// #include <set>
// #include <cassert>
// #include <limits>
// using namespace std;

const double EPS = 1e-9;

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
