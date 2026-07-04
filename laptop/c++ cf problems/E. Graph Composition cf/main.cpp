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

struct dsu{
    vector<int> parent;
    vector<int> cnt;
    dsu(int n){
        parent.resize(n);
        cnt.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int _find(int i){
        if(i!=parent[i]){
            parent[i] = _find(parent[i]);
        }
        return parent[i];
    }
    bool unite(int a, int b){
        int x = _find(a);
        int y = _find(b);
        if(x==y) return false;
        if(cnt[x]<cnt[y]){
            swap(x,y);
        }
        parent[y] = x;
        cnt[x]+=cnt[y];
        return true;
    }
};


void solve(){
    int n,m1,m2;
    cin >> n >> m1 >>  m2;
    vector<vi> adj(n);
    for(int i=0;i<m1;i++){
        int a,b;
        cin >> a >> b;
        if(a>b){
            swap(a,b);
        }
        adj[--a].pb(--b);
    }
    dsu tree1(n);
    dsu tree2(n);
    for(int i=0;i<m2;i++){
        int a,b;
        cin >> a >> b;
        --a;--b;
        tree2.unite(a,b);
    }
    map<int,vi> bucket;
    for(int i=0;i<n;i++){
        bucket[tree2._find(i)].pb(i);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int x : adj[i]){
            if(tree2._find(x) == tree2._find(i)){
                tree1.unite(x,i);
            } else{
                ++ans;
            }
        }
    }
    for(auto x : bucket){
        set<int> u;
        for(auto y : x.ss){
            u.insert(tree1._find(y));
        }
        if(u.size()){
            ans+=(u.size()-1);
        }
    }
    cout << ans << "\n";
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
