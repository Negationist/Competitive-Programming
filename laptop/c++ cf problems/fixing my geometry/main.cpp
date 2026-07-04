#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

template<typename T>
T sign(T x){
    if(x<0){
        return -1;
    } else if(x>0){
        return 1;
    } else return 0;
}

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
    friend int mag(const Point &a){
        return a.x*a.x+a.y*a.y;
    }
    friend bool ccw(const Point &a, const Point &b, const Point &c){
       Point seg1 = b-a;
       Point seg2 = c-a;
       int res = seg1^seg2;
       return (res>0);
    }
    void debug() const {
        std::cout << "this point is (" << x << ", " << y << ")\n";
    }
    friend vi hull_ind(vector<Point> &p){
        int _n = p.size();
        int pivot = 0;
        for(int i=1;i<_n;i++){
            if(p[i].y<p[pivot].y){
                pivot = i;
            } else if(p[pivot].y==p[i].y){
                if(p[i].x<p[pivot].x){
                    pivot = i;
                }
            }
        }
        vector<int> sorted;
        map<pii,bool> seen;
        seen[{p[pivot].x,p[pivot].y}] = true;
        for(int i=0;i<_n;i++){
            pii cur = {p[i].x,p[i].y};
            if(!seen[cur]){
                seen[cur] = true;
                sorted.pb(i);
            }
        }
        sort(sorted.begin(),sorted.end(),
             [&](const int &i, const int &j){
                    Point<int> x = p[i]-p[pivot];
                    Point<int> y = p[j]-p[pivot];
                    int cross = x^y;
                    if(cross>0){
                        return true;
                    } else if(cross<0){
                        return false;
                    } else{
                        return (mag(x) < mag(y));
                    }
                }
             );
        stack<int> cand;
        cand.push(pivot);
        for(int i=0;i<sorted.size();i++){
            int cur = sorted[i];
            while(true){
                if(cand.size()==1){
                    cand.push(cur);
                    break;
                } else{
                    int y = cand.top();
                    cand.pop();
                    int x = cand.top();
                    if(ccw(p[x],p[y],p[cur])){
                        cand.push(y);
                        cand.push(cur);
                        break;
                    }
                }
            }
        }
        int num = cand.size();
        vi res(num);
        int j = num-1;
        while(cand.size()){
            res[j] = (cand.top());
            cand.pop();
            --j;
        }
        return res;
    }
    friend vector<pair<Point,Point>> all_antipodal(vector<Point> &hull){ //pass this a convex hull
        int n = hull.size();
        vector<pair<Point,Point>> res;
        auto next = [&](int x){
            return (x+1<n?x+1:x+1-n);
        };
        auto prev = [&](int x){
            return (x-1>=0?x-1:x-1+n);
        };
        int p1 = 0, p2 = 0;
        vector<bool> visited(n,false);
        for(;p1<n;p1++){
            Point base = hull[next(p1)] - hull[p1];
            while(p1==p2 || p2==next(p1) || sign(base^(hull[p2]-hull[prev(p2)]))==sign(base^(hull[next(p2)]-hull[p2]))){
                p2 = next(p2);
            }
            if(visited[p1]) continue;
            visited[p1] = true;
            res.pb({hull[p1],hull[p2]});
            res.pb({hull[next(p1)],hull[p2]});
            if((base^(hull[next(p2)]-hull[p2]))==0){
                visited[p2] = true;
                res.pb({hull[p1],hull[next(p2)]});
                res.pb({hull[next(p1)],hull[next(p2)]});
            }
        }
        return res;
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
