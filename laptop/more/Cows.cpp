#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define sz(x) (int)(x).size()
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

template <class T>
int sgn(T x) {
    return (x > 0) - (x < 0);
}

template <class T>
struct Point {
    typedef Point P;

    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }

    P operator+(P p) const {
        return P(x + p.x, y + p.y);
    }

    P operator-(P p) const {
        return P(x - p.x, y - p.y);
    }

    P operator*(T d) const {
        return P((ll)x * d, (ll)y * d);
    }

    P operator/(T d) const {
        return P(x / d, y / d);
    }

    ll dot(P p) const {
        return (ll)x * (ll)p.x + (ll)y * (ll)p.y;
    }

    ll cross(P p) const {
        return (ll)x * (ll)p.y - (ll)y * (ll)p.x;
    }

    ll cross(P a, P b) const {
        return (a - *this).cross(b - *this);
    }

    ll dist2() const {
        return (ll)x * x + (ll)y * y;
    }

    double dist() const {
        return sqrt((double)dist2());
    }

    // angle to x-axis in interval [-pi, pi]
    double angle() const {
        return atan2(y, x);
    }

    P unit() const {
        return *this / dist();
    } // makes dist() = 1

    P perp() const {
        return P(-y, x);
    } // rotates +90 degrees

    P normal() const {
        return perp().unit();
    }

    // returns point rotated 'a' radians CCW around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }

    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<int> P;

struct PointHash {
    size_t operator()(const P& p) const {
        ll h1 = hash<ll>{}(p.x);
        ll h2 = hash<ll>{}(p.y);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};

vector<P> result_points;

struct Quad{
    const int max_nodes = 64;
    // const ll min_size = ; not needed I think
    P topLeft, bottomRight;
    bool isLeaf = true;
    unordered_set<P, PointHash> data;

    Quad* topLeftChild = nullptr;
    Quad* topRightChild = nullptr;
    Quad* bottomLeftChild = nullptr;
    Quad* bottomRightChild = nullptr;

    Quad(P tl, P br){
        topLeft = tl;
        bottomRight = br;
    }

    ~Quad(){
        delete topLeftChild;
        delete topRightChild;
        delete bottomLeftChild;
        delete bottomRightChild;
    }

    pair<P, P> getTopLeftChildBounds(){ //need to verify all 4, replace the pairs with points
        ll m_hor = ((ll)topLeft.y + bottomRight.y) / 2;
        ll m_vert = ((ll)topLeft.x + bottomRight.x) / 2;
        P x = topLeft;
        P y(m_vert, m_hor + 1);
        return {x,y};
    }
    pair<P, P> getTopRightChildBounds(){
        ll m_hor = ((ll)topLeft.y + bottomRight.y) / 2;
        ll m_vert = ((ll)topLeft.x + bottomRight.x) / 2;
        P x(m_vert + 1, topLeft.y);
        P y(bottomRight.x, m_hor + 1);
        return {x,y};
    }
    pair<P, P> getBottomLeftChildBounds(){
        ll m_hor = ((ll)topLeft.y + bottomRight.y) / 2;
        ll m_vert = ((ll)topLeft.x + bottomRight.x) / 2;
        P x(topLeft.x, m_hor);
        P y(m_vert, bottomRight.y);
        return {x,y};

    }
    pair<P, P> getBottomRightChildBounds(){
        ll m_hor = ((ll)topLeft.y + bottomRight.y) / 2;
        ll m_vert = ((ll)topLeft.x + bottomRight.x) / 2;
        P x(m_vert + 1, m_hor);
        P y = bottomRight;
        return {x,y};
    }

    bool contains(P p){
        bool a = (topLeft.x <= p.x), b = (bottomRight.x >= p.x), c = ((topLeft.y >= p.y)), d = (bottomRight.y <= p.y);
        return (a && b && c && d);
    }

    void insert(P x){
        if(this->contains(x) == false) return;
        int old_num = sz(data);
        data.insert(x);
        if(sz(data) > max_nodes && old_num <= max_nodes){
            isLeaf = false;
            //make the top left child
            auto [tl1, br1] = getTopLeftChildBounds(); 
            topLeftChild = new Quad(tl1, br1);
            //make the top right child
            auto [tl2, br2] = getTopRightChildBounds();
            topRightChild = new Quad(tl2, br2);
            auto [tl3, br3] = getBottomLeftChildBounds();
            bottomLeftChild = new Quad(tl3, br3);
            //make the bottom right child
            auto [tl4, br4] = getBottomRightChildBounds();
            bottomRightChild = new Quad(tl4, br4);
            for(P p : this->data){
                bottomRightChild->insert(p);
                bottomLeftChild->insert(p);
                topRightChild->insert(p);
                topLeftChild->insert(p);
            }
        } else if(sz(data) > max_nodes){
            bottomRightChild->insert(x);
            bottomLeftChild->insert(x);
            topRightChild->insert(x);
            topLeftChild->insert(x);
        }
    }

    void remove(P x){
        if(this->contains(x) == false) return;
        if(isLeaf){
            this->data.erase(x);
        } else{
            bottomRightChild->remove(x);
            bottomLeftChild->remove(x);
            topRightChild->remove(x);
            topLeftChild->remove(x);
            this->data.erase(x);
            if((sz(topLeftChild -> data) + sz(topRightChild -> data) + sz(bottomLeftChild -> data) + sz(bottomRightChild -> data)) <= max_nodes){
                delete bottomRightChild;
                delete bottomLeftChild;
                delete topRightChild;
                delete topLeftChild;
                bottomRightChild = nullptr;
                bottomLeftChild = nullptr;
                topRightChild = nullptr;
                topLeftChild = nullptr;
                isLeaf = true;
            }
        }
    }
    void query(P tl, P br){
        if(this->isLeaf){
            for(P p : this->data){
                if(Quad(tl, br).contains(p)){
                    result_points.pb(p);
                }
            }
        } else if(this->topLeft.x >= tl.x && this->topLeft.y<= tl.y && this->bottomRight.x <= br.x && this->bottomRight.y >= br.y){
            for(P p : this->data){
                result_points.pb(p);
            }
        } else if(this->bottomRight.x < tl.x || this->topLeft.x > br.x || this->topLeft.y < br.y || this->bottomRight.y > tl.y){
            return;
        } else{
            bottomRightChild->query(tl, br);
            bottomLeftChild->query(tl, br);
            topRightChild->query(tl, br);
            topLeftChild->query(tl, br);
        }
    }
};

vector<P> convexHull(vector<P> &pts) {
    if (sz(pts) <= 1) {
        return pts;
    }
    sort(pts.begin(), pts.end());
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end())) {
        for (P p : pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) {
                t--;
            }
            h[t++] = p;
        }
    }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
template<class P>
int sideOf(P s, P e, P p) {
    return sgn(s.cross(e, p));
}

template<class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
    auto a = (e - s).cross(p - s);
    double l = (e - s).dist() * eps;
    return (a > l) - (a < -l);
}



bool inHull(const vector<P>& l, P p, bool strict = true) {
    if(sz(l) == 0) return false;
    int a = 1, b = sz(l) - 1, r = !strict;
    if (sz(l) < 3) {
        return r && onSegment(l[0], l.back(), p);
    }
    if (sideOf(l[0], l[a], l[b]) > 0) {
        swap(a, b);
    }
    if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p) <= -r) {
        return false;
    }
    while (abs(a - b) > 1) {
        int c = (a + b) / 2;
        (sideOf(l[0], l[c], p) > 0 ? b : a) = c;
    }
    return sgn(l[a].cross(l[b], p)) < r;
}


void solve(){
    int n; cin >> n;
    Quad posts(P(-(1LL<<n),(1LL<<n)), P((1LL<<n), -(1LL<<n)));
    Quad cows(P(-(1LL<<n),(1LL<<n)), P((1LL<<n), -(1LL<<n)));
    int c,p; cin >> c >> p;
    vector<P> loc(c);
    for(int i=0;i<c;i++){
        int x,y; cin >> x >> y;
        loc[i] = P(x,y);
        cows.insert(P(x,y));
    }
    for(int i=0;i<p;i++){
        int x,y; cin >> x >> y;
        posts.insert(P(x,y));
    }
    int q; cin >> q;
    while(q--){
        char ch; cin >> ch;
        if(ch == 'Q'){
            int x1, x2, x3, x4; cin >> x1 >> x2 >> x3 >> x4;
            Quad temp(P(x1, x2), P(x3, x4));
            result_points.clear();
            posts.query(P(x1, x2), P(x3, x4));
            vector<P> hull = convexHull(result_points);
            result_points.clear();
            cows.query(P(x1, x2), P(x3, x4));
            int num_hull = 0, num_tot = 0;
            for(P p : result_points){
                if(inHull(hull, p, false)){
                    ++num_hull;
                }
                if(temp.contains(p)){
                    ++num_tot;
                }
            }
            cout << num_hull << " ";
            cout << num_tot - num_hull << "\n";
        } else{
            int i; cin >> i;
            int x,y; cin >> x >> y;
            cows.remove(loc[i]);
            loc[i] = P(x,y);
            cows.insert(loc[i]);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
