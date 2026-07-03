#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

struct segTree{
    vector<int> tree;
    int n;
    segTree(vector<int> &a){
        int _n = a.size();
        int log = 31-__builtin_clz(_n);
        log+=(__builtin_popcount(_n)>1);
        n = 1LL<<log;
        int num = n<<1LL;
        tree.assign(num,0);
        for(int i=0;i<a.size();i++){
            tree[i+n] = a[i];
        }
        for(int i=n-1;i>=1;i--){
            tree[i] = gcd(tree[i*2],tree[i*2+1]);
        }
    }
    int query(int a, int b){
        int res = 0;
        a+=n; b+=n;
        while(a<=b){
            if(a&1) res= gcd(res,tree[a++]);
            if(!(b&1)) res=gcd(res,tree[b--]);
            a>>=1; b>>=1;
        }
        return res;
    }
    void _replace(int i, int x){
        int index = i+n;
        tree[index]=x;
        while(index>1){
            index>>=1LL;
            tree[index] = gcd(tree[index*2],tree[index*2+1]);
        }
    }
};


void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    vi next(n,n+100);
    stack<pii> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
        while(s.size() && s.top().ff!=a[i]){
            int cur = s.top().ss;
            next[cur] = i;
            s.pop();
        }
        s.push({a[i],i});
    }
    vector<int> z(n-1);
    for(int i=0;i<n-1;i++){
        z[i] = abs(a[i]-a[i+1]);
    }
    segTree tree(z);
    while(q--){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        if(r<next[l]){
            cout << "0 ";
        } else{
            r--;
            cout << tree.query(l,r) << " ";
        }
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
