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

void normalize(int &x){
    if(x){
        x/=abs(x);
    }
}

struct Point{
    int x,y;
    Point(){
        x = 0; y = 0;
    }
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    Point operator-(const Point &other) const {
        return Point(this->x-other.x,this->y-other.y);
    }
    Point operator+(const Point &other) const {
        return Point(this->x+other.x,this->y+other.y);
    }
    friend istream &operator>>(istream &in, Point &p) {
		in >> p.x >> p.y;
		return in;
	}
	int operator^(const Point &other) const{
        return (x*other.y)-(other.x*y);
    }
    static int shoelace(const vector<Point> &a){ //returns double the area
        int n = a.size();
        int sum = 0;
        for(int i=0;i+1<n;i++){
            sum+=(a[i].x*a[i+1].y-a[i].y*a[i+1].x);
        }
        sum+=(a[n-1].x*a[0].y-a[n-1].y*a[0].x);
        return abs(sum);
    }
    void debug(){
        cout << "this point is (" << x << ", " << y << ")\n";
    }
};

struct lineSeg{
    int x1,y1,x2,y2;
    lineSeg() : x1(0), y1(0), x2(0), y2(0) {}
    lineSeg(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d){};
    lineSeg(Point &a, Point &b){
        x1 = a.x; y1 = a.y; x2 = b.x; y2 = b.y;
    }
    friend istream& operator>>(istream& in, lineSeg &seg){
        in >> seg.x1 >> seg.y1 >> seg.x2 >> seg.y2;
        return in;
    }
    static bool parallel(lineSeg &a, lineSeg &b){ //assumes they intersect
        int res1 = (a.y2-a.y1)*(b.x2-b.x1);
        int res2 = (b.y2-b.y1)*(a.x2-a.x1);
        return (res1==res2);
    }
    bool contains(Point &a){
        Point line = Point(x2,y2)-Point(x1,y1);
        Point z = a-Point(x1,y1);
        bool res = line^z;
        bool contain1 = ((min(x1,x2)<=a.x)&&(max(x1,x2)>=a.x));
        bool contain2 = ((min(y1,y2)<=a.y)&&(max(y1,y2)>=a.y));
        return (res==0 && contain1 && contain2);
    }
    long double length(){
        long double res = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        return res;
    }
    friend bool strict_intersect(lineSeg a, lineSeg b){
        int t1 = max(a.y1,a.y2);
        int b1 = min(a.y1,a.y2);
        int t2 = max(b.y1,b.y2);
        int b2 = min(b.y1,b.y2);
        if(max(b1,b2)>min(t1,t2)) return false;
        int r1 = max(a.x1,a.x2);
        int l1 = min(a.x1,a.x2);
        int r2 = max(b.x1,b.x2);
        int l2 = min(b.x1,b.x2);
        if(max(l1,l2)>min(r1,r2)) return false;
        Point c1(a.x1,a.y1);
        Point c2(a.x2,a.y2);
        Point d1(b.x1,b.y1);
        Point d2(b.x2,b.y2);
        int cross1 = (d2-d1)^(c2-d1);
        normalize(cross1);
        int cross2 = (d2-d1)^(c1-d1);
        normalize(cross2);
        int cross3 = (c2-c1)^(d1-c1);
        normalize(cross3);
        int cross4 = (c2-c1)^(d2-c1);
        normalize(cross4);
        if(cross1*cross2<0 && cross3*cross4<0){
            return true;
        } else{
            return false;
        }
    }
    friend bool intersect(lineSeg a, lineSeg b){
        int t1 = max(a.y1,a.y2);
        int b1 = min(a.y1,a.y2);
        int t2 = max(b.y1,b.y2);
        int b2 = min(b.y1,b.y2);
        if(max(b1,b2)>min(t1,t2)) return false;
        int r1 = max(a.x1,a.x2);
        int l1 = min(a.x1,a.x2);
        int r2 = max(b.x1,b.x2);
        int l2 = min(b.x1,b.x2);
        if(max(l1,l2)>min(r1,r2)) return false;
        Point c1(a.x1,a.y1);
        Point c2(a.x2,a.y2);
        Point d1(b.x1,b.y1);
        Point d2(b.x2,b.y2);
        int cross1 = (d2-d1)^(c2-d1);
        normalize(cross1);
        int cross2 = (d2-d1)^(c1-d1);
        normalize(cross2);
        int cross3 = (c2-c1)^(d1-c1);
        normalize(cross3);
        int cross4 = (c2-c1)^(d2-c1);
        normalize(cross4);
        if(cross1*cross2<=0 && cross3*cross4<=0){
            return true;
        } else{
            return false;
        }
    }
    void debug(){
        cout << "this segment goes from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << "\n";
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<Point> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    while(m--){
        int x,y;
        cin >> x >> y;
        Point z(x,y);
        int num = 0;
        bool flag = false;
        for(int i=0;i<n;i++){
            int j = (i+1)%n;
            lineSeg temp(a[i],a[j]);
            if(temp.contains(z)){
                cout << "BOUNDARY\n";
                flag = true;
                break;
            }
            if(a[i].y<=y && y<a[j].y){
                Point v1 = z-a[i];
                Point v2 = z-a[j];
                if((v1^v2)>0){
                    ++num;
                }
            }
            if(a[j].y<=y && y<a[i].y){
                Point v1 = z-a[j];
                Point v2 = z-a[i];
                if((v1^v2)>0){
                    ++num;
                }
            }
        }
        if(flag) continue;
        if(num&1){
            cout << "INSIDE\n";
        } else{
            cout << "OUTSIDE\n";
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
