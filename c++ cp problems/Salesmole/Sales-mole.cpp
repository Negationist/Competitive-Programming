#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P((ll)x*d, (ll)y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return (ll)x*p.x + (ll)y*p.y; }
	T cross(P p) const { return (ll)x*p.y - (ll)y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return (ll)x*x + (ll)y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> void segInter(P a, P b, P c, P d, bool &cooked, set<P> &intersections, bool &blessed) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0){
        cooked = true;
        return;
    }
	set<P> s;
	if (onSegment(c, d, a)){
        s.insert(a);
        intersections.insert(a);
    }
	if (onSegment(c, d, b)){
        s.insert(b);
        intersections.insert(b);
    }
	if (onSegment(a, b, c)){
        s.insert(c);
        intersections.insert(c);
    }
	if (onSegment(a, b, d)){
        s.insert(d);
        intersections.insert(d);
    }
    if(sz(s) == 2) blessed = true;
}


template <class P>
bool lineCrossHull(P a, P b, vector<P>& poly) {
    int n = sz(poly);
    set<P> intersections;
    for (int i = 0; i < n; i++) {
        P c = poly[i], d = poly[(i + 1) % n];
        bool cooked = false, blessed = false;
        segInter(a,b,c,d, cooked, intersections, blessed);
        if(cooked == true) return true;
        if(blessed == true) return false;
    }
    if(sz(intersections) <= 1){ //no intersections or just a touch
        return false;
    } else{ //there are always 2 otherwise
        return true;
    }
}

const ll inf = 1e17;

struct dsu{
    vector<int> parent;
    vector<int> cnt;
    dsu(int n){
        parent.resize(n);
        cnt.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int _find(int i){
        if(i!=parent[i]){
            parent[i] = _find(parent[i]);
        }
        return parent[i];
    }
    bool unite(int a, int b){
        int x = _find(a);
        int y = _find(b);
        if(x==y) return false;
        if(cnt[x]<cnt[y]){
            swap(x,y);
        }
        parent[y] = x;
        cnt[x]+=cnt[y];
        return true;
    }
};

const int maxN = 2100;
const double eps = 1e-9;

int nxt[maxN][maxN] = {};
double dist[maxN][maxN] = {};
int owner[maxN];

void solve(){
    int n,m; cin >> n >> m;
    Point<int> c[n];
    vector<Point<int>> map;
    for(int i=0;i<n;i++){
        cin >> c[i].x >> c[i].y;
        map.pb(c[i]);
        owner[i] = -1;
    }
    vector<vector<Point<int>>> hull(m, vector<Point<int>>()); //need to check for colinear points if they have annoying input
    for(int i=0;i<m;i++){
        int z; cin >> z;
        hull[i].resize(z);
        for(int j=0;j<z;j++){
            cin >> hull[i][j].x >> hull[i][j].y;
            map.pb(hull[i][j]);
            owner[sz(map) - 1] = i;
        }
    }
    int num = sz(map);
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(owner[i] == owner[j] && owner[i] != -1) continue;
            bool flag = false;
            for(int k=0;k<m;k++){
                if(lineCrossHull(map[i], map[j], hull[k])){
                    flag = true;
                    break;
                }
            }
            if(i == j) {
                dist[i][j] = 0;
                nxt[i][j] = j;
            }
            else if(!flag){
                dist[i][j] = (sqrt((ll)(map[i].x - map[j].x) * (map[i].x - map[j].x) + (ll)(map[i].y - map[j].y) * (map[i].y - map[j].y)));
                nxt[i][j] = j;
            } else{
                dist[i][j] = inf;
                nxt[i][j] = -1;
            }
        }
    }
    int ptr = n;
    for(int h=0;h<m;h++){
        for(int a=0; a<sz(hull[h]); a++){
            for(int b=0; b < sz(hull[h]); b++){
                int i = ptr + a;
                int j = ptr + b;
                if(i == j){
                    dist[i][j] = 0;
                    nxt[i][j] = i;
                } else {
                    dist[i][j] = inf;
                    nxt[i][j] = -1;
                }
            }
        }
        for(int a = 0; a < sz(hull[h]); a++){
            int b = (a + 1) % sz(hull[h]);
            int i = ptr + a;
            int j = ptr + b;
            double w = sqrt((ll)(map[i].x - map[j].x) * (map[i].x - map[j].x) + (ll)(map[i].y - map[j].y) * (map[i].y - map[j].y));
            dist[i][j] = dist[j][i] = w;
            nxt[i][j] = j;
            nxt[j][i] = i;
        }
        ptr += sz(hull[h]);
    }
    for(int k=0;k<num;k++){
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(dist[i][k] + dist[k][j] + eps < dist[i][j]){
                    nxt[i][j] = nxt[i][k];
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    vector<tuple<double,int,int>> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges.pb({dist[i][j], i, j});
        }
    }
    sort(all(edges));
    vector<vi> adj(n, vi());
    dsu tree(n);
    for(auto [w, i, j] : edges){
        if(tree.unite(i,j)){
            adj[i].pb(j);
            adj[j].pb(i);
        }
    }
    vi out;
    auto dfs = [&](auto self, int x, int p)->void {
        out.pb(x);
        for(int y : adj[x]){
            if(y!=p){
                self(self, y, x);
            }
        }
    };
    dfs(dfs, 0, -1);
    out.pb(0);
    for(int i=0;i<sz(out)-1;i++){
        cout << map[out[i]].x << " " << map[out[i]].y << "\n";
        int cur = nxt[out[i]][out[i+1]];
        while(cur != out[i+1]){
            cout << map[cur].x << " " << map[cur].y << "\n";
            cur = nxt[cur][out[i+1]];
        }

    }
    cout << map[out[0]].x << " " << map[out[0]].y << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}