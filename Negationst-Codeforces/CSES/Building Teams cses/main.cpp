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
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vi ans(n);
    bool win = true;
    vector<bool> visited(n, false);
    auto dfs = [&](auto self, int cur, int color)->void{
        visited[cur] = true;
        ans[cur] = color;
        for(int x : adj[cur]){
            if(!visited[x]){
                self(self,x,(color==1 ? 2 : 1));
            } else{
                if(ans[x]==ans[cur]){
                    win = false;
                }
            }
        }
    };
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(dfs,i,1);
        }
    }
    if(win){
        for(int x : ans){
            cout << x << " ";
        }
    } else{
        cout << "IMPOSSIBLE\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
