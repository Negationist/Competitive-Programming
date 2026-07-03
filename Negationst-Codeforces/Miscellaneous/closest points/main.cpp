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
    friend T shoelace(const vector<Point> &a) { // returns double the area
        int n = a.size();
        T sum = 0;
        for(int i = 0; i + 1 < n; i++) {
            sum += (a[i].x * a[i+1].y - a[i].y * a[i+1].x);
        }
        sum += (a[n-1].x * a[0].y - a[n-1].y * a[0].x);
        return abs(sum);
    }
    friend ld dist(const Point &a, const Point &b){
        ld dx = a.x-b.x, dy = a.y-b.y;
        return sqrt(dx*dx + dy*dy);
    }
    friend ld s_dist(const Point &a, const Point &b){
        ld dx = a.x-b.x, dy = a.y-b.y;
        return (dx*dx + dy*dy);
    }
    void debug() const {
        std::cout << "this point is (" << x << ", " << y << ")\n";
    }
};
const ld eps = 1e-9;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(2);
    while(true){
        int n;
        cin >> n;
        if(!n) break;
        vector<Point<ld>> p(n);
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        sort(p.begin(),p.end(),
             [](const Point<ld> &a, const Point<ld> &b){
                if(a.x!=b.x) return a.x<b.x;
                return a.y<b.y;
             }
             );
        auto cmp = [&](const Point<ld> &a, const Point<ld> &b){
            if(a.y!=b.y){
                return a.y<b.y;
            }
            return a.x<b.x;
        };
        pair<Point<ld>, Point<ld>> ans = {p[0],p[1]};
        ld delta = dist(ans.ff,ans.ss);
        //cout << delta << "!\n";
        set<Point<ld>,decltype(cmp)> window(cmp);
        window.insert(p[0]);
        window.insert(p[1]);
        int j = 0;
        for(int i=2;i<n;i++){
            while(p[j].x+delta<p[i].x){
                window.erase(p[j]);
                ++j;
            }
            Point<ld> temp(p[i].x,p[i].y+delta);
            if(window.size()){
               auto it = window.lower_bound(temp);
               if(it==window.end()) it--;
               int inc = 0;
               while(true && inc<20){
                    Point<ld> cur = *(it);
                    //cur.debug();
                    //p[i].debug();
                    if(dist(p[i],cur)<delta){
                        ans = {p[i],cur};
                        delta = dist(p[i],cur);
                    }
                    if(it==window.begin()) break;
                    it--;
                    ++inc;
               }
            }
            window.insert(p[i]);
        }
        cout << ans.ff.x << " " << ans.ff.y << " " <<  ans.ss.x << " " << ans.ss.y << "\n";
    }
    return 0;
}
