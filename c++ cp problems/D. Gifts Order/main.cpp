#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

template <typename T, T (*op)(T, T), T identity>
struct segTree {
    vector<T> tree;
    int n;

    segTree(vector<T>& a) {
        int _n = a.size();
        int log = 31 - __builtin_clz(_n);
        log += (__builtin_popcount(_n) > 1);
        n = 1LL << log;
        int num = n << 1LL;
        tree.assign(num, identity);
        for (int i = 0; i < a.size(); i++) {
            tree[i + n] = a[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            tree[i] = op(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    T query(int a, int b) {
        T res = identity;
        a += n; b += n;
        while (a <= b) {
            if (a & 1) res = op(res, tree[a++]);
            if (!(b & 1)) res = op(res, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return res;
    }

    void update(int i, T x) {
        int index = i + n;
        tree[index] = x;
        while (index > 1) {
            index >>= 1;
            tree[index] = op(tree[index * 2], tree[index * 2 + 1]);
        }
    }
};

int range_sum(int a, int b) {
    return a + b;
}

int range_min(int a, int b) {
    return min(a, b);
}

int range_max(int a, int b) {
    return max(a, b);
}


void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    auto b = a;
    reverse(b.begin(),b.end());
    for(int i=0;i<n;i++){
        a[i]-=i;
        b[i]+=i;
    }
    segTree<int,range_max,LLONG_MIN> mxtree(a);
    segTree<int,range_min,LLONG_MAX> mntree(a);
    segTree<int,range_max,LLONG_MIN> mxtree2(b);
    segTree<int,range_min,LLONG_MAX> mntree2(b);
    auto getans = [&](){
        int res1 = mxtree.query(0,n-1)-mntree.query(0,n-1);
        int res2 = mxtree2.query(0,n-1)-mntree2.query(0,n-1);
        return max(res1,res2);
    };
    cout << getans() << "\n";
    while(q--){
        int p,x;
        cin >> p >> x;
        --p;
        mxtree.update(p,x-p);
        mntree.update(p,x-p);
        mxtree2.update(p,x+p);
        mntree2.update(p,x+p);
        cout << getans() << "\n";
    }
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
