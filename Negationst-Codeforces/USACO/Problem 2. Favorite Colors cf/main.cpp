#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

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
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    dsu tree(n);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
    }
    for(int i=0;i<n;i++){
        int first = -1;
        for(int x : adj[i]){
            if(first==-1){
                first = x;
            } else{
                tree.unite(first,x);
            }
        }
    }
    map<int,int> ans;
    int inc = 1;
    for(int i=0;i<n;i++){
        int x = tree._find(i);
        if(ans[x]==0){
            ans[x] = inc++;
        }
        cout << ans[x] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
