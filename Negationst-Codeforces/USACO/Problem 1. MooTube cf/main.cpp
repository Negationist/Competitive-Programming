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
    int n,q;
    cin >> n >> q;
    dsu net(n);
    vector<int> ans(q);
    vector<pair<int,pii>> edges(n-1);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.pb({-c,{a,b}});
    }
    vector<pair<int,pii>> queries;
    for(int i=0;i<q;i++){
        int k,v;
        cin >> k >> v;
        v--;
        queries.pb({-k,{v,i}});
    }
    sort(edges.begin(),edges.end());
    sort(queries.begin(),queries.end());
    int index = 0;
    for(int i=0;i<q;i++){
        int cur = -queries[i].ff;
        while(index<n && -edges[index].ff >= cur){
            net.unite(edges[index].ss.ff, edges[index].ss.ss);
            index++;
        }
        int par = net._find(queries[i].ss.ff);
       ans[queries[i].ss.ss] = net.cnt[par]-1;
    }
    for(int x : ans){
        cout << x << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out", "w", stdout);
    solve();
    return 0;
}
