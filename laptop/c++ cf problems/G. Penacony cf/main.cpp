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
using ll = long long;
enum QueryType {SET, NONE };

struct Tag {
    QueryType type = NONE;
    ll val = 0;
    void apply(const Tag &t) {
        if (t.type == SET) {
            type = SET;
            val = t.val;
        }
    }
};

struct Info {
    ll min_val = LLONG_MAX, min_cnt = 0;
    void apply(const Tag &t, int l, int r) {
        if (t.type == SET) {
            min_val = t.val;
            min_cnt = r-l+1;
        }
    }
    friend Info operator+(const Info &a, const Info &b) {
        if(a.min_val<b.min_val){
            return {a.min_val,a.min_cnt};
        } else if(a.min_val>b.min_val){
            return {b.min_val,b.min_cnt};
        } else{
            return {a.min_val,b.min_cnt+a.min_cnt};
        }
    }
};

template<class Info, class Tag>
struct lazySegTree {
    int n;
    vector<Info> tree;
    vector<Tag> lazy;

    void build(int v, int l, int r, vector<Info> &a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    void apply(int v, int l, int r, const Tag &t) {
        tree[v].apply(t, l, r);
        lazy[v].apply(t);
    }

    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, l, m, lazy[v]);
        apply(2 * v + 1, m + 1, r, lazy[v]);
        lazy[v] = Tag();
    }

    void range_update(int v, int l, int r, int ql, int qr, const Tag &t) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(v, l, r, t);
        } else {
            push_down(v, l, r);
            int m = (l + r) / 2;
            range_update(2 * v, l, m, ql, qr, t);
            range_update(2 * v + 1, m + 1, r, ql, qr, t);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    Info range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Info();
        if (ql <= l && r <= qr) return tree[v];
        push_down(v, l, r);
        int m = (l + r) / 2;
        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
    }

    lazySegTree(int n) {
        this->n = n;
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
    }

    lazySegTree(vector<Info> &a) {
        n = a.size();
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
        build(1, 0, n - 1, a);
    }

    void range_update(int ql, int qr, const Tag &t) {
        range_update(1, 0, n - 1, ql, qr, t);
    }

    Info range_query(int ql, int qr) {
        return range_query(1, 0, n - 1, ql, qr);
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    vii r(m);
    for(int i=0;i<m;i++){
        cin >> r[i].ff >> r[i].ss;
        --r[i].ff;
        --r[i].ss;
    }
    lazySegTree<Info,Tag> tree(n-1);
    int ans = 1;
    for(int i=0;i<n;i++){ //no road from i to i+1, i.e line starts at i+1
        tree.range_update(0,n-2,{SET,0});
        for(int j=0;j<m;j++){
            int x = (r[j].ff-(i+1)+n)%n;
            int y = (r[j].ss-(i+1)+n)%n;
            tree.range_update(min(x,y),max(x,y)-1,{SET,1});
        }
        Info temp = tree.range_query(0,n-2);
        if(temp.min_val==0){
            ans = max(ans,1+temp.min_cnt);
        }
    }
    cout << n-ans << "\n";
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
