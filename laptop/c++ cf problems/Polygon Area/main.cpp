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

struct Point{
    int x,y;
    Point(){
        x = 0; y = 0;
    }
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    Point operator-(const Point &other){
        return Point(this->x-other.x,this->y-other.y);
    }
    Point operator+(const Point &other){
        return Point(this->x+other.x,this->y+other.y);
    }
    friend istream &operator>>(istream &in, Point &p) {
		in >> p.x >> p.y;
		return in;
	}
	static int cross(Point a, Point b){
        return a.x*b.y-b.x*a.y;
    }
    static int shoelace(vector<Point> &a){ //returns double the area
        int n = a.size();
        int sum = 0;
        for(int i=0;i+1<n;i++){
            sum+=(a[i].x*a[i+1].y-a[i].y*a[i+1].x);
        }
        sum+=(a[n-1].x*a[0].y-a[n-1].y*a[0].x);
        return abs(sum);
    }
};


void solve(){
    int n;
    cin >> n;
    vector<Point> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << Point::shoelace(a) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
