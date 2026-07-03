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
    friend int dist(Point &a, Point &b){ //returns the squared distance
        int res = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        return res;
    }
    void debug(){
        cout << "this point is (" << x << ", " << y << ")\n";
    }
};

int numPoints(vector<vector<int>>& darts, int r) {
    int n = darts.size();
    vector<Point>
    for(int i=0;i<n;i++){

    }
}

void solve(){
    int n,r;
    cin >> n >> r;
    vector<vi> darts(n,vi(2));
    for(int i=0;i<n;i++){
        cin >> darts[i][0] >> darts[i][1];
    }
    int ans = numPoints(darts,r);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
