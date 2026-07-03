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
    int node;
    int mx = -1;
    auto dfs1 = [&](auto self, int cur, int p, int dis)->void{
        if(dis>mx){
            node = cur;
            mx = dis;
        }
        for(int x : adj[cur]){
            if(x!=p){
                self(self,x,cur,dis+1);
            }
        }
    };
    dfs1(dfs1,0,-1,0);
    int root = node;
    vi far(n);
    vi par(n);
    priority_queue<pii> pq;
    auto dfs2 = [&](auto self, int cur, int p, int dis)->pii{
        par[cur] = p;
        bool is = true;
        pii res;
        for(int x : adj[cur]){
            if(x!=p){
                is = false;
                pii cur2 = self(self,x,cur,dis+1);
                if(cur2.ss>res.ss){
                    res = cur2;
                }
            }
        }
        if(is){
            res = {cur,dis};
        }
        far[cur] = res.ff;
        pq.push({res.ss-dis, cur});
        return res;
    };
    dfs2(dfs2,root,-1,0);
    //cout << root << "!\n";
    //for(int i=0;i<n;i++){
    //    cout << "far " << i << " is " << far[i] << "\n";
    //}
    vi visited(n,0);
    vi ans(n+1);
    int tot = 1;
    ans[1] = tot;
    visited[root] = true;
    for(int i=2;i<=n;i++){
        bool done = false;
        while(!done && tot<n){
            int cur = pq.top().ss;
            pq.pop();
            if(!visited[cur]){
                done = true;
                visited[cur] = true;
                tot++;
                //cout << "up on " << cur << "\n";
                int son = far[cur];
                while(son != cur){
                    visited[son] = true;
                    //cout << "up on " << son << "\n";
                    son = par[son];
                    tot++;
                }
            }
        }
        ans[i] = tot;
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
