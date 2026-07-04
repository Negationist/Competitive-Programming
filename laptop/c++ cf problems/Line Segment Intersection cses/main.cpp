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

int normalize(int x){
    if(x){
        x/=abs(x);
    }
    return x;
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
    Point operator-(const Point &other) const{
        return Point(this->x-other.x,this->y-other.y);
    }
    Point operator+(const Point &other) const{
        return Point(this->x+other.x,this->y+other.y);
    }
    int operator^(const Point &other) const{
        return (x*other.y)-(other.x*y);
    }
};

struct lineSeg{
    int x1,y1,x2,y2;
    lineSeg() : x1(0), y1(0), x2(0), y2(0) {}
    lineSeg(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d){};
    friend istream& operator>>(istream& in, lineSeg &seg){
        in >> seg.x1 >> seg.y1 >> seg.x2 >> seg.y2;
        return in;
    }
};

bool intersect(lineSeg a, lineSeg b){
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
    cross1 = normalize(cross1);
    int cross2 = (d2-d1)^(c1-d1);
    cross2 = normalize(cross2);
    int cross3 = (c2-c1)^(d1-c1);
    cross3 = normalize(cross3);
    int cross4 = (c2-c1)^(d2-c1);
    cross4 = normalize(cross4);
    if(cross1*cross2<=0 && cross3*cross4<=0){
        return true;
    } else{
        return false;
    }
}

void solve(){
    lineSeg a;
    lineSeg b;
    cin >> a >> b;
    if(intersect(a,b)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
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
