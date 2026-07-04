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

struct Point {
    int x,y;
    int cross(Point a, Point b){
        return a.x*b.y-a.y*b.x;
    }
    Point(){
        x = 0;
        y = 0;
    }
    Point(int i, int j){
        x = i;
        y = j;
    }
};

Point operator+(Point a, Point b) {
    return {a.x + b.x, a.y + b.y};
}
Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

bool operator<(Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}


void solve(){
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point s1
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
