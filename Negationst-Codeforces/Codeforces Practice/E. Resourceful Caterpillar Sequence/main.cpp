#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vector<bool> isleaf(n,0);
    vector<bool> isgood(n,0);
    int num = 0;
    for(int i=0;i<n;i++){
        if(adj[i].size()==1){
            isleaf[i] = true;
            num++;
        }
    }
    int ans = (num)*(n-num);
    vii sub(n);
    vi depth(n);
    depth[0] = 0;
    int tot = 0;
    auto dfs = [&](auto self, int cur, int p)->void{
        bool notgood = false;
        notgood|=isleaf[cur];
        if(cur){
            depth[cur] = depth[p]+1;
        }
        sub[cur] = {1,0}; //{size,"good" nodes}
        for(int x : adj[cur]){
            notgood|=isleaf[x];
            if(x==p) continue;
            self(self,x,cur);
            sub[cur].ff+=sub[x].ff;
            sub[cur].ss+=sub[x].ss;
        }
        if(!notgood){
            sub[cur].ss++;
            isgood[cur] = true;
            tot++;
        }
    };
    dfs(dfs,0,-1);
    vector<int> visited(n,false);
    for(int i=0;i<n;i++){
        if(adj[i].size()!=1) continue;
        int x = adj[i][0];
        for(int y : adj[x]){ //y is aaron's start
            if(y==i) continue;
            if(depth[y]>depth[x]){ //y is below
                int good = tot-sub[y].ss-isgood[x];
                ans+=good;
            } else{
                int good = sub[x].ss;
                ans+=good;
            }
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
