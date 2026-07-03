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

struct slope_trick {
    int m = 0, b = 0, range = 1;
    map<int,int> points;
    bool use_history = false;
    bool use_tree    = false;
    vector<tuple<int,int,int>> changes;
    unique_ptr<Segtree<int,decltype(op)>> tree; //needs some work
    slope_trick(bool enable_history = false,
                bool enable_tree    = false,
                int  m_init         = 0,
                int  b_init         = 0,
                int  range_limit    = 1)
                : m(m_init), b(b_init), range(range_limit), use_history(enable_history), use_tree(enable_tree){
                if (use_tree){
                    tree = make_unique<Segtree<int,decltype(op)>>(op, 0LL, 2*range + 1);
                }
    }
    int  shift(int x) const {
        return x + range;
    }
    void log_change (int type,int x,int d){
        if(use_history) changes.push_back({type,x,d});
    }
    void add_slope(int x,int delta){
        if(!delta) return;
        points[x] += delta;
        if (points[x]==0) points.erase(x);
        if (use_tree) tree->set(shift(x), points.count(x)?points[x]:0);
        log_change(3,x,delta);
    }
    bool set_max(int mx){
        int m_old = m, b_old = b;
        while(m>mx && !points.empty()){
            auto it  = points.rbegin();
            int  x   = it->first;
            int  cnt = it->second;
            int  y   = m*x + b;
            if(m-cnt<=mx){
                int diff = m-mx;
                m = mx;
                it->second -= diff;
                log_change(3,x,-diff);
            }else{
                m -= cnt;
                log_change(3,x,-cnt);
                points.erase(std::prev(it.base()));
            }
            if(points.count(x)==0 && use_tree) //why use .count? just use points[x], OOHHH is it to not create a zero pair? nice!
                tree->set(shift(x),0);
            else if(use_tree)
                tree->set(shift(x),points[x]);
            b = y - m*x;
        }
        log_change(1,m-m_old,0);
        log_change(2,b-b_old,0);
        return m<=mx;
    }

    bool set_min(int mn){
        if(m<mn) return false;
        int cur=m,gone=0;
        for(auto it=points.rbegin();it!=points.rend();){
            int cnt = it->second;
            int x   = it->first;
            if(gone){
                log_change(3,x,-cnt);
                if(use_tree) tree->set(shift(x),0);
                it = reverse_iterator(points.erase(prev(it.base())));
            }else if(cur-cnt<mn){
                gone = 1;
                int take = cnt-(cur-mn);
                it->second -= take;
                log_change(3,x,-take);
                if(it->second==0){
                    if(use_tree) tree->set(shift(x),0);
                    it = reverse_iterator(points.erase(prev(it.base())));
                }else{
                    if(use_tree) tree->set(shift(x),it->second);
                    ++it;
                }
            }else ++it;
        }
        return true;
    }
    slope_trick& operator+=(const slope_trick& other){
        m += other.m;  b += other.b;
        log_change(1,other.m,0);
        log_change(2,other.b,0);
        for(auto [x,d] : other.points){
            add_slope(x,d);
        }
        return *this;
    }
    slope_trick operator+(const slope_trick& o) const{
        slope_trick res(use_history||o.use_history,
                      use_tree   ||o.use_tree,
                      m+o.m,b+o.b,
                      max(range,o.range));
        res.points = points;
        for(auto [x,d] : other.points){
            res.points[x]+=d;
        }
        if(res.use_tree){
            for(auto [x,d] : res.points){
                res.add_slope(x,0);
            }
        }
        return res;
    }
    static slope_trick abs_func(int slope,int point){
        slope_trick s;
        s.m=slope; s.b=-point; s.points[point]=2*slope;
        return s;
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
