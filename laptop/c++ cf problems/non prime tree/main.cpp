#include <bits/stdc++.h>
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

void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n,vi());
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vector<int> ans(n);
    int x = 2, y = 2*n;
    auto dfs = [&](auto self, int cur, int p, int d)->void{
        if(d&1){
            ans[cur] = x;
            x+=2;
        } else{
            ans[cur] = y;
            y-=2;
        }
        bool is = true;
        for(int x : adj[cur]){
            if(x!=p){
                is = false;
                self(self, x, cur, d+1);
            }
        }
        if(is && abs(ans[cur]-ans[p])==2){
            ans[cur] = ans[p]-1;
        }
    };
    dfs(dfs, 0, -1, 0);
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
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
