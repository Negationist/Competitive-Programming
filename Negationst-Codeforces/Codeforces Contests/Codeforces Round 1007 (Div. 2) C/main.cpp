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
void solve(){
    int n,s,e;
    cin >> n >> s >> e;
    --e;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    priority_queue<pii> pq;
    auto dfs = [&](auto self, int x, int p, int d)->void{
        //cout << x << "\n";
        pq.push({d,x});
        for(int y : adj[x]){
            if(y!=p){
               self(self,y,x,d+1);
            }
        }
    };
    dfs(dfs,e,-1,0);
    while(pq.size()){
        cout << pq.top().ss+1 << " ";
        pq.pop();
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
