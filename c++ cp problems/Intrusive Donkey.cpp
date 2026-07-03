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
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;


struct Tag {
    ll a = 1, b = 0;
    void apply(const Tag &t) {
        a = a * t.a;
        b = t.a*b + t.b;
    }
};

struct Info {
    ll sum = 0, max_val = LLONG_MIN;
    void apply(const Tag &t, int l, int r) {
        sum = sum*t.a+t.b*(r-l+1);
        max_val = max_val*t.a+t.b;
    }
    friend Info operator+(const Info &a, const Info &b) {
        return {a.sum + b.sum, max(a.max_val, b.max_val)};
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

    lazySegTree(const vector<Info> &a) {
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
    int n,q;
    cin >> n >> q;
    string s; cin >> s;
    lazySegTree<Info, Tag> tree(n);
    tree.range_update(0,n-1,{0,1});
    while(q--){
        int z;
        cin >> z;
        if(z==1){
            int l,r;
            cin >> l >> r;
            int lo = 0, hi = n-1;
            int x,y;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                int res = tree.range_query(0,mid).sum;
                if(res>=l){
                    hi = mid-1;
                } else{
                    lo = mid+1;
                }
            }
            x = lo;
            lo = 0, hi = n-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                int res = tree.range_query(0,mid).sum;
                if(res>=r){
                    hi = mid-1;
                } else{
                    lo = mid+1;
                }
            }
            // for(int i=0;i<n;i++){
            //     cout << tree.range_query(i,i).sum << " ";
            // }
            // cout << "\n";
            y = lo;
            //cout << "x is " << x+1 << " y is " << y+1 << "\n";
            if(x!=y){
                int add_x = tree.range_query(x,x).sum - (l-1 - (x?tree.range_query(0,x-1).sum:0)/*number of things that are not in*/);
                //cout << "added " << add_x << " to " << x+1 << "\n";
                int add_y = r - (y?tree.range_query(0,y-1).sum:0);
                //cout << "added " << add_y << " to " << y+1 << "\n";
                tree.range_update(x,x,{1,add_x});
                tree.range_update(y,y,{1,add_y});
            } else{
                int num = r-l+1;
                tree.range_update(x,x,{1,num});
                //cout << "added " << num << " to " << x+1 << "\n";
            }
            if(y>=x+2){
                tree.range_update(x+1,y-1,{2,0});
            }
            // for(int i=0;i<n;i++){
            //     cout << tree.range_query(i,i).sum << " ";
            // }
            // cout << "\n";
        } else{
            int i;
            cin >> i;
            int lo = 0, hi = n-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                int res = tree.range_query(0,mid).sum;
                if(res>=i){
                    hi = mid-1;
                } else{
                    lo = mid+1;
                }
            }
            cout << s[lo] << "\n";
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