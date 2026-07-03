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
    int mx = 0;
    int index;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
        if(adj[u].size()>mx){
            mx = adj[u].size();
            index = u;
        }
        if(adj[v].size()>mx){
            mx = adj[v].size();
            index = v;
        }
    }
    cout << n-1-mx << "\n";
    auto dfs = [&](auto self, int cur, int p)->void{
        if(cur==index){
            for(int x : adj[cur]){
                self(self,x,cur);
            }
        } else{
            for(int x : adj[cur]){
                if(x==p) continue;
                cout << index+1 << " " << cur+1 << " " << x+1 << "\n";
            }
            for(int x : adj[cur]){
                if(x==p) continue;
                self(self,x,cur);
            }
        }
    };
    dfs(dfs,index,-1);
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
