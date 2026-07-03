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
    vector<vii> adj(n);
    for(int i=0;i<m;i++){
        int a,b,l;
        cin >> a >> b >> l;
        adj[--a].pb({--b,l});
    }
    vii ans(n);
    vector<bool> visited(n,false);
    vi next(n,-1);
    auto dfs = [&](auto self, int cur){
        visited[cur] = true;
        if(adj[cur].size()==0){
            ans[cur] = {0,0};
            return;
        }
        int mx = -1;
        int mn = LLONG_MAX;
        int index;
        for(auto x : adj[cur]){
            int c = x.ff;
            if(visited[c]==false){
                self(self, c);
            }
            int mx = -1;
            int best = -1;
            if(ans[c].ss > mx){
                mx = ans[c].ss;
            }
        }
    };
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(dfs,i);
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i].ff << " " << ans[i].ss << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
