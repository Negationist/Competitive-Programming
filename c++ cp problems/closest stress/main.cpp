#include <bits/stdc++.h>
using namespace std;
using ld = long double;

template<typename T>
struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(T _x, T _y) : x(_x), y(_y) {}
    Point operator-(const Point &other) const {
        return Point(this->x - other.x, this->y - other.y);
    }
    Point operator+(const Point &other) const {
        return Point(this->x + other.x, this->y + other.y);
    }
    friend istream &operator>>(istream &in, Point &p) {
        in >> p.x >> p.y;
        return in;
    }
    T operator^(const Point &other) const {
        return (x * other.y) - (other.x * y);
    }
};

ld dist(const Point<ld> &a, const Point<ld> &b) {
    ld dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// Brute-force closest pair algorithm (O(n^2))
pair<Point<ld>, Point<ld>> bruteForceClosestPair(const vector<Point<ld>> &points) {
    int n = points.size();
    pair<Point<ld>, Point<ld>> best = {points[0], points[1]};
    ld bestDist = dist(points[0], points[1]);
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            ld d = dist(points[i], points[j]);
            if (d < bestDist) {
                bestDist = d;
                best = {points[i], points[j]};
            }
        }
    }
    return best;
}

// Your sweep-line closest pair algorithm (modified stress-test version)
pair<Point<ld>, Point<ld>> sweepLineClosestPair(vector<Point<ld>> p) {
    int n = p.size();
    if(n < 2) return {p[0], p[0]};
    sort(p.begin(), p.end(), [](const Point<ld> &a, const Point<ld> &b) {
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    auto cmp = [&](const Point<ld> &a, const Point<ld> &b){
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    };

    pair<Point<ld>, Point<ld>> ans = {p[0], p[1]};
    ld delta = dist(ans.first, ans.second);
    set<Point<ld>, decltype(cmp)> window(cmp);
    window.insert(p[0]);
    window.insert(p[1]);
    int j = 0;
    for (int i = 2; i < n; i++){
        while(p[j].x + delta < p[i].x){
            window.erase(p[j]);
            ++j;
        }
        // Create a temporary point to find lower_bound in y dimension.
        Point<ld> temp(p[i].x, p[i].y + delta);
        if(!window.empty()){
            auto it = window.lower_bound(temp);
            if(it == window.end()) it--;
            int inc = 0;
            while(true && inc < 20){
                Point<ld> cur = *it;
                if(dist(p[i], cur) < delta){
                    ans = {p[i], cur};
                    delta = dist(p[i], cur);
                }
                if(it == window.begin()) break;
                it--;
                ++inc;
            }
        }
        window.insert(p[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(NULL));
    int T = 10000; // number of test iterations
    for (int t = 0; t < T; t++){
        // Generate a small test case with n between 2 and 11.
        int n = rand() % 10 + 2;
        vector<Point<ld>> points(n);
        for (int i = 0; i < n; i++){
            // Random points in range [-100, 100]
            ld x = (rand() % 201) - 100;
            ld y = (rand() % 201) - 100;
            points[i] = Point<ld>(x, y);
        }

        auto ansBrute = bruteForceClosestPair(points);
        auto ansSweep = sweepLineClosestPair(points);
        ld d1 = dist(ansBrute.first, ansBrute.second);
        ld d2 = dist(ansSweep.first, ansSweep.second);

        // Check if the distances differ significantly
        if (fabs(d1 - d2) > 1e-9) {
            cout << "Mismatch found on test case " << t+1 << "\n";
            cout << "Number of points: " << n << "\n";
            cout << "Points:\n";
            for (auto &pt : points) {
                cout << pt.x << " " << pt.y << "\n";
            }
            cout << "\nBrute force pair: ("
                 << ansBrute.first.x << ", " << ansBrute.first.y << ") and ("
                 << ansBrute.second.x << ", " << ansBrute.second.y << ") with distance " << d1 << "\n";
            cout << "Sweep line pair: ("
                 << ansSweep.first.x << ", " << ansSweep.first.y << ") and ("
                 << ansSweep.second.x << ", " << ansSweep.second.y << ") with distance " << d2 << "\n";
            return 0;
        }
    }
    cout << "All tests passed.\n";
    return 0;
}
