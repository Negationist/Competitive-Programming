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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dsu tree(n);
    for(int i=0;i<n;i++){
        for(int x : adj[i]){
            if(a[x]==a[i]) tree.unite(i,x);
        }
    }
    set<int> s1,s2;
    for(int i=0;i<n;i++){
        int par = tree._find(i);
        if(a[par]==0){
            s1.insert(par);
        } else{
            s2.insert(par);
        }
    }
    cout << min(s1.size(),s2.size()) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
