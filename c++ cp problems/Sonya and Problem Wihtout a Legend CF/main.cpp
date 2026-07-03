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

struct slope_trick{ //holds change history, be careful with memory
    int m,b;
    map<int,int> points;
    vii changes; //if you want this, put it somewhere
    slope_trick(int m, int b, map<int,int> points) // don't allow any non-positive map values
        : m(m), b(b), points(points){}
    slope_trick(): m(0), b(0) {}
    slope_trick operator+(const slope_trick& other) const{
        slope_trick res;
        res.m = m + other.m;
        res.b = b + other.b;
        for(auto &[x,y] : points){
            res.points[x]+=y;
        }
        for(auto &[x,y] : other.points){
            res.points[x]+=y;
        }
        return res;
    }
    slope_trick& operator+=(const slope_trick& other) {
        m += other.m;
        b += other.b;
        for (auto &[x,y] : other.points) {
            points[x] += y;
            changes.pb({x,y});
        }
        return *this;
    }
    bool set_max(int mx){
        while(m>mx && points.size()){
            auto it = points.rbegin();
            int x = it->ff, cnt = it->ss;
            int y = m*x+b;
            if(m-cnt<=mx){
                int diff = m-mx;
                m = mx;
                (it->ss)-=diff;
                changes.pb({x,-diff});
                if(it->ss==0){
                    points.erase(prev(it.base()));
                }
                b = y - m*x;
            } else{
                m-=cnt;
                changes.pb({x,-cnt});
                points.erase(prev(it.base()));
                b = y - m*x;
            }
        }
        return (m<=mx);
    }
    bool set_min(int mn){
        if(m<mn) return false;
        int cur = m, gone = 0;
        for (auto it = points.rbegin(); it != points.rend();){
            int cnt = it->ss;
            if (gone) {
                changes.pb({it->ff,-cnt});
                it = reverse_iterator(points.erase(prev(it.base())));
            } else if(cur-cnt<mn){
                gone = 1;
                int allowed = cur-mn;
                (it->ss) = allowed;
                int amount = cnt-allowed;
                changes.pb({it->ff,-amount});
                if(!allowed){
                    it = reverse_iterator(points.erase(prev(it.base())));
                }
            } else{
                ++it;
            }
        }
        return true;
    }
    static slope_trick abs_func(int slope, int point){
        map<int,int> temp;
        temp[point] = 2;
        return slope_trick(slope,-point,temp);
    }
};

void solve(){
    int n;
    cin >> n;
    slope_trick f;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        z-=i;
        f = f+slope_trick::abs_func(1,z);
        f.set_max(0);
    }
    cout << f.b << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
