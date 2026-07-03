#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;

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
    int n; cin >> n;
    dsu tree(n);
    vector<vi> adj(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> adj[i][j];
            if(adj[i][j] && min(i,j)!=0){
                tree.unite(i,j);
            }
        }
    }
    map<int,vi> sets;
    for(int i=0;i<n;i++){
        sets[tree._find(i)].pb(i);
    }
    for(int i=0;i<n;i++){
        if(sets[i].size()){
            for(int x : sets[i]){
                cout << x+1 << " ";
            }
            cout << "\n";
        }
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
