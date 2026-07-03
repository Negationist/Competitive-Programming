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

enum QueryType {};

struct Tag{
    int nA, nB;
};

struct Info{
    int sum = 0,rA = 0,rB = 0;
    void apply(const Tag &t){
        sum = min(t.nA,t.nB);
        rA = t.nA-sum;
        rB = t.nB-sum;
    }
    friend Info operator+(const Info &l, const Info &r) {
        int take = min(l.rA,r.rB);
        return {l.sum+r.sum+take, l.rA+r.rA-take, l.rB+r.rB-take};
    }
    void debug(){
        cout << "sum is " << sum << ", rA is " << rA << ", rB is " << rB << "\n";
    }
};

template <typename Info, typename Tag>
struct segTree {
    int n;
    vector<Info> tree;
    segTree(int n){
        this->n = n;
        tree.assign(4 << __lg(n), Info());
    }
    segTree(const vector<Info> &a){
        n = a.size();
        tree.assign(4 << __lg(n), Info());
        build(1,0,n-1,a);
    }
    void build(int x, int l, int r, vector<Info> &a) {
        if(l==r){
            tree[x] = a[l];
        } else{
            int m = (l + r) / 2;
            build(2 * x, l, m, a);
            build(2 * x + 1, m + 1, r, a);
        }
    }
    void update(int x, int l, int r, int i, Tag v) {
        if (l == r) {
            tree[x].apply(v);
            return;
        }
        int m = (l + r) / 2;
        if (i <= m){
           update(2 * x, l, m, i, v);
        }
        else{
            update(2 * x + 1, m + 1, r, i, v);
        }
        tree[x] = tree[2*x] + tree[2 * x + 1];
    }
    void update(int i, Tag v) {
        update(1, 0, n - 1, i, v);
    }
    Info query(int x, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Info();
        if (ql <= l && r <= qr) return tree[x];
        int m = (l + r) / 2;
        return query(2 * x, l, m, ql, qr) + query(2 * x + 1, m + 1, r, ql, qr);
    }
    Info query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n),b(n),c(n-1);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n-1;i++) cin >> c[i];
    segTree<Info,Tag> tree(n);
    for(int i=0;i<n;i++){
        tree.update(i,{a[i],b[i]});
    }
    while(q--){
        int p,x,y,z;
        cin >> p >> x >> y >> z;
        --p;
        tree.update(p,{x,y});
        Info res = tree.query(0,n-1);
        cout << res.sum << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
