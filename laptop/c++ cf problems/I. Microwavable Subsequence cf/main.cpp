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
            tree[i] = tree[i*2]+tree[i*2+1];
        }
    }
    int sum(int a, int b){
        int res = 0;
        a+=n; b+=n;
        while(a<=b){
            if(a&1) res+=tree[a++];
            if(!(b&1)) res+=tree[b--];
            a>>=1; b>>=1;
        }
        return res;
    }
    void update(int i, int x){
        int index = i+n;
        tree[index]+=x;
        while(index>1){
            index>>=1LL;
            tree[index] = tree[index*2]+tree[index*2+1];
        }
    }
    void _replace(int i, int x){
        int index = i+n;
        tree[index]=x;
        while(index>1){
            index>>=1LL;
            tree[index] = tree[index*2]+tree[index*2+1];
        }
    }
};


void solve(){
    int n,m;
    cin >> n >> m;
    vi a(n);
    vi last(m+1,-1);
    vii q;
    set<int> exist;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(last[a[i]]+1>=0 && i-1>=0 && last[a[i]]+1<=i-1){
            q.pb({last[a[i]]+1,i-1});
        }
        last[a[i]] = i;
        exist.insert(a[i]);
    }
    sort(q.begin(),q.end(),
         [&](pii a, pii b){
            return a.ss < b.ss;
         }
         );
    vi b(n,0);
    segTree tree(b);
    last.assign(m+1,-1);
    int j = -1;
    int ans = 0;
    for(int i=0;i<q.size();i++){
        if(q[i].ss>j){
            ++j;
        }
        while(true){
            tree._replace(j,1);
            if(last[a[j]]!=-1){
                tree._replace(last[a[j]],0);
            }
            last[a[j]] = j;
            if(j+1<=q[i].ss){
                ++j;
            } else{
                break;
            }
        }
        ans+=tree.sum(q[i].ff,q[i].ss);
        cout << q[i].ff << " " << q[i].ss << " is " << tree.sum(q[i].ff,q[i].ss) << "\n";
    }
    for(int i=1;i<=m;i++){
        if(exist.find(i)!=exist.end()){
            ans+=(n-exist.size());
        }
        exist.insert(i);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
