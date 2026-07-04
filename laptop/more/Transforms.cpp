#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr double pi = 3.141592653589793238462643383279502884;

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j] += d[i][k]*m.d[k][j];
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i,0,N) rep(j,0,N) ret[i] += d[i][j] * vec[j];
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};


enum TagType {Translate, NonTranslate};

struct Tag{
    TagType type;
    Matrix<double,2> A_p;
    double dx = 0,dy = 0;
};

struct Info{
    Matrix<double,2> A, B;
    Info(){
        A.d = {{{1,0}, {0,1}}};
        B.d = {{{0,0}, {0,0}}};
    };
    void apply(const Tag &t){
        if(t.type ==  Translate){
            B.d[0][0]+=t.dx;
            B.d[1][0]+=t.dy;
        } else{
            A = t.A_p * A;
            B = t.A_p * B;
        }
    }

    friend Info operator+(const Info &a, const Info &b) {
        Info res;
        res.A = b.A * a.A;
        res.B = b.A * a.B;
        res.B.d[0][0]+=b.B.d[0][0];
        res.B.d[1][0]+=b.B.d[1][0];
        return res;
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
    void build(int x, int l, int r, const vector<Info> &a) {
        if(l==r){
            tree[x] = a[l];
        } else{
            int m = (l + r) / 2;
            build(2 * x, l, m, a);
            build(2 * x + 1, m + 1, r, a);
            tree[x] = tree[2*x] + tree[2 * x + 1];
        }
    }
    void update(int x, int l, int r, int i, Tag v) {
        if (l == r) {
            tree[x] = Info();
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

double deg_to_rad(double d){
    return d * pi / 180.0;
}

Tag getTag() {
    string s; cin >> s;
    Tag t;
    if(s[0] == 'T'){
        double dx,dy;
        cin >> dx >> dy;
        t.type = Translate;
        t.dx = dx;
        t.dy = dy;

    } else if(s[0] == 'S'){
        double sx, sy; cin >> sx >> sy;
        t.type = NonTranslate;
        t.A_p.d = {{{sx,0}, {0,sy}}};
    } else{
        double d; cin >> d;
        t.type = NonTranslate;
        t.A_p.d = {{{cos(deg_to_rad(d)), -sin(deg_to_rad(d))}, {sin(deg_to_rad(d)), cos(deg_to_rad(d))}}};
    }
    return t;
}

void solve(){
    int n,q; cin >> n >> q;
    vector<Info> base(n);
    for (int i = 0; i < n; i++) {
        Tag t = getTag();
        base[i] = Info();
        base[i].apply(t);
    }
    segTree<Info, Tag> tree(base);
    cout << fixed << setprecision(15);
    while(q--){
        char c; cin >> c;
        if(c == 'Q'){
            double x,y; cin >> x >> y;
            int l,r; cin >> l >> r;
            Info transform = tree.query(l,r);
            Matrix<double, 2> pos;
            pos.d = {{{x,0}, {y,0}}};
            pos = transform.A * pos;
            pos.d[0][0]+=transform.B.d[0][0];
            pos.d[1][0]+=transform.B.d[1][0];
            cout << "(" << ll(x) << "," << ll(y) << "): " << pos.d[0][0] << " " << pos.d[1][0]  << "\n";
        } else{
            int i; cin >> i;
            Tag t = getTag();
            tree.update(i,t);
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