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
    string s;
    cin >> s;
    int n = s.size();
    if(n&1){
        cout << "impossible\n";
        return;
    }
    vi val(n);
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            val[i] = 1;
        } else{
            val[i] = -1;
        }
    }
    vi pref(n+2);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+val[i-1];
    }
    pref[n+1] = LLONG_MAX; //fix later
    segTree<int,range_min,LLONG_MAX> mntree(pref);
    segTree<int,range_max,LLONG_MIN> mxtree(pref);
    int need = pref[n]/2;
    bool win = false;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            if(pref[r]-pref[l-1]!=need){
                continue;
            }
            bool good = true;
            int mn1 = mntree.query(0,l-1);
            int mx = mxtree.query(l,r);
            int mn2 = mntree.query(r+1,n+1)-pref[r];
            if(mn1<0) good = false;
            if(-mx+2*pref[l-1]<0) good = false;
            if(2*pref[l-1]-pref[r]+mn2<0) good = false;
            if(good){
                win = true;
            }
        }
    }
    if(!need && mntree.query(0,n)==0) win = true;
    if(win){
        cout << "possible\n";
    } else{
        cout << "impossible\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
