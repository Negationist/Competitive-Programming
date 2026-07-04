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
const int maxN = 1e5+10;
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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vi pos(n+5);
    for(int i=0;i<n;i++){
        pos[a[i]] = i;
    }
    vi b(maxN,0);
    segTree tree(b);
    vi ans(n+5);
    for(int i=n;i>=1;i--){
        int r = pos[i];
        //cout << r+1 << "! ";
        ans[i] = tree.sum(0,pos[i]);
        //cout << ans[i] << "!\n";
        tree.update(pos[i],1);
        //cout << "tree " << r+1 << " is " << 1 << "\n";
    }
    for(int i=0;i<n;i++){
        cout << ans[a[i]] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
