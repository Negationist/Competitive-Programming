#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int maxN = 1e5+5;
const int mod = 998244353;
vi a(maxN);
vll h(maxN); //hanoi i + 1

void compute(){
    h[0] = 1;
    h[1] = 2;
    for(int i=2;i<maxN;i++){
        h[i] = (h[i-1]*2)%mod;
    }
}

int mex(int a, int b){
    vi temp(3,0);
    temp[a] = temp[b] = 1;
    for(int i=0;i<3;i++){
        if(!temp[i]){
            return i;
        }
    }
}

ll binPowMod(ll b, ll p, ll mod){
    ll res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}

ll modInv(ll x, ll mod){
    return binPowMod(x,mod-2,mod);
}

struct Info{
    ll val[3];
    ll pnt[3];
    Info(){};
    static Info merge(Info &a, Info &b){
        Info res;
        for(int i=0;i<3;i++){
            res.val[i] = b.val[i];
            int x = b.pnt[i];
            res.val[i]+=a.val[x];
            res.val[i]%=mod;
            res.pnt[i] = a.pnt[x];
        }
        return res;
    }
    void set(int x){
        for(int i=0;i<3;i++){
            if(a[x]==i){
                val[i] = 0;
                pnt[i] = i;
            } else{
                val[i] = h[x];
                pnt[i] = mex(a[x],i);
            }
        }
    }
    void debug(){
        for(int i=0;i<3;i++){
            cout << "val[" << i << "] is " << val[i] << ". pnt[" << i << "] is " << pnt[i] << "\n";
        }
    }
};

struct Segtree {
    int n;
    vector<Info> tree;
    Segtree(int n) : n(n) {
        tree.assign(4 << __lg(n),Info());
    }
    void build(int x, int l, int r) {
        if (l == r) {
            tree[x].set(l);
            /*cout << "on node " << x << "\n";
            cout << "range is (" << l << ", " << r << ")\n";
            tree[x].debug();*/
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        tree[x] = Info::merge(tree[2*x],tree[2*x+1]);
    }
    void build() {
        build(1, 0, n - 1);
    }
    void set(int x, int l, int r, int i) {
        if (l == r) {
            tree[x].set(l);
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            set(2 * x, l, m, i);
        else
            set(2 * x + 1, m + 1, r, i);
        tree[x] = Info::merge(tree[2 * x], tree[2 * x + 1]);
    }
    void set(int i) {
        set(1, 0, n - 1, i);
    }
    void query(int x, int l, int r, int ql, int qr, vii &res) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr){
            res.pb({-r,x});
            return;
        }
        int m = (l + r) / 2;
        query(2 * x, l, m, ql, qr,res);
        query(2 * x + 1, m + 1, r, ql, qr,res);
    }

    vii query(int l, int r) {
        vii res;
        query(1, 0, n - 1, l, r, res);
        sort(res.begin(),res.end());
        return res;
    }
};

void solve(){
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
        --a[i];
    }
    Segtree g_tree(n);
    g_tree.build();
    while(q--){
        char x;
        cin >> x;
        int l,r;
        cin >> l >> r;
        --l;
        --r;
        if(x=='c'){
            a[l] = r;
            g_tree.set(l);
        } else{
            vii temp = g_tree.query(l,r);
            ll ans = 0;
            int pntr = 0;
            for(int i=0;i<temp.size();i++){
                int cur = temp[i].ss;
                ans += g_tree.tree[cur].val[pntr];
                ans%=mod;
                pntr = g_tree.tree[cur].pnt[pntr];
            }
            ans = ans*modInv(h[l],mod);
            ans%=mod;
            cout << ans << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
