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
const int mod = 998244353;

int binPowMod(int b, int p, int mod){
    int res = 1;
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

int modInv(int x, int mod){
    return binPowMod(x,mod-2,mod);
}

template <typename T, typename F>
struct segTree {
    int n;
    vector<T> tree;
    F merge;
    T identity;

    segTree(F merge_op, T id, int n) : merge(merge_op), identity(id), n(n) {
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
        return query(1, 0, n - 1, l, r);
    }
};

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int sum = (binPowMod(2,n,mod)-1+mod)%mod;
    vi b(n,0);
    auto op = [&](int a, int b){
        return a+b;
    };
    segTree<int, decltype(op)>tree(op,0,n); tree.build(b);
    auto flip = [&](int x)->void{
        int a = (x==0?0:x-tree.query(0,x-1)); //0s to the left
        int b = (x==n-1?0:n-x-1-tree.query(x+1,n-1)); //0s to right
        int c = (x==0?0:tree.query(0,x-1)); //1s to left
        int d = (x==n-1?0:tree.query(x+1,n-1)); //1s to right
        if(tree.tree[x]==0){
            sum+=(a*b);
            sum-=(c*d);
            sum = (sum+10*mod)%mod;
            tree.set(x,1);
        } else{
            sum-=(a*b);
            sum+=(c*d);
            sum = (sum+10*mod)%mod;
            tree.set(x,0);
        }
    };
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            flip(i);
        }
    }
    cout << sum << "!\n";
    int q;
    cin >> q;
    while(q--){
        int z;
        cin >> z;
        --z;
        flip(z);
        cout << sum << " ";
    }
    cout << "\n";
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
