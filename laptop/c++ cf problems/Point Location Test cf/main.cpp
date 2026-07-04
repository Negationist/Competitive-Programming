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
};

int cross(Point a, Point b){
    return a.x*b.y-b.x*a.y;
}

void solve(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    Point s1(a,b);
    Point s2(c,d);
    Point p(e,f);
    Point line = s2-s1;
    Point z = p-s1;
    int res = cross(line,z);
    if(res>0){
        cout << "LEFT\n";
    }else if(res<0){
        cout << "RIGHT\n";
    } else{
        cout << "TOUCH\n";
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
