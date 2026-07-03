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

template <typename T, typename F>

void op(int a, int b){
    return a+b;
}

struct Segtree {
    int n;
    vector<T> tree;
    F merge;
    T identity;

    Segtree(F merge_op, T id, int n) : merge(merge_op), identity(id), n(n) {
        tree.assign(4 << __lg(n), identity);
    }

    void build(vector<T> &a, int x, int l, int r) {
        if (l == r) {
            if (l < (int)a.size()) tree[x] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, 2 * x, l, m);
        build(a, 2 * x + 1, m + 1, r);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void build(vector<T> &a) {
        build(a, 1, 0, n - 1);
    }

    void set(int x, int l, int r, int i, T v) {
        if (l == r) {
            tree[x] = v;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            set(2 * x, l, m, i, v);
        else
            set(2 * x + 1, m + 1, r, i, v);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void set(int i, T v) {
        set(1, 0, n - 1, i, v);
    }

    T query(int x, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return identity;
        if (ql <= l && r <= qr) return tree[x];
        int m = (l + r) / 2;
        return merge(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
    }

    T query(int l, int r) {
        if(l>r) return identity;
        return query(1, 0, n - 1, l, r);
    }
};

struct slope_trick{ //holds change history, be careful with memory
    int m,b,range = 2e5;
    map<int,int> points;
    Segtree<int,decltype(op)> tree(op,0LL,range);
    vector<pair<int,pair<int,int>>> changes;
    slope_trick(int m, int b, map<int,int> points) // don't allow any non-positive map values
        : m(m), b(b), points(points){}
    slope_trick(): m(0), b(0) {}
    void log_change(int x, int y, int z){
        changes.pb({x,{y,z}});
    }
    void rollback(int num){
        assert(num>=0);
        while((int)changes.size()>num){
            int x = changes.back().ff, y = changes.back().ss.ff, z = changes.back().ss.ss;
            if(x==1){
                m-=y;
            } else if(x==2){
                b-=y;
            } else{
                points[y]-=z;
                if(points[y]==0){
                    points.erase(y);
                }
            }
            changes.pop_back();
        }
    }
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
        log_change(1,other.m,0);
        log_change(2,other.b,0);
        for (auto &[x,y] : other.points) {
            log_change(3,x,y);
            points[x] += y;
        }
        return *this;
    }
    bool set_max(int mx){
        int m_old = m, b_old = b;
        while(m>mx && points.size()){
            auto it = points.rbegin();
            int x = it->ff, cnt = it->ss;
            int y = m*x+b;
            if(m-cnt<=mx){
                int diff = m-mx;
                m = mx;
                (it->ss)-=diff;
                log_change(3,x,-diff);
                if(it->ss==0){
                    points.erase(prev(it.base()));
                }
                b = y - m*x;
            } else{
                m-=cnt;
                log_change(3,x,-cnt);
                points.erase(prev(it.base()));
                b = y - m*x;
            }
        }
        log_change(1,m-m_old,0);
        log_change(2,b-b_old,0);
        return (m<=mx);
    }
    bool set_min(int mn){
        if(m<mn) return false;
        int cur = m, gone = 0;
        for (auto it = points.rbegin(); it != points.rend();){
            int cnt = it->ss;
            if (gone) {
                log_change(3,it->ff,-cnt);
                it = reverse_iterator(points.erase(prev(it.base())));
            } else if(cur-cnt<mn){
                gone = 1;
                int amount = cnt-(cur-mn);
                (it->ss)-=amount;
                log_change(3,it->ff,-amount);
                if(!(it->ss)){
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
        temp[point] = 2*slope;
        return slope_trick(slope,-point,temp);
    }
};

void solve(){
    int n,c,d;
    cin >> n >> c >> d;
    slope_trick f = slope_trick::abs_func(1e6,0);
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
