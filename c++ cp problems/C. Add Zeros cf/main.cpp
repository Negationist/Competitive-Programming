#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int ans;
void dfs(int cur, map<int,set<int>>&adj, map<int,bool> &visited){
    ans = max(ans,cur);
    visited[cur]=true;
    for(int x : adj[cur]){
        if(x==1 || visited[cur+x-1]) continue;
        dfs(cur+x-1, adj,visited);
    }
}

void solve(){
    ans=0;
    int n;
    cin >> n;
    vi a(n+1);
    map<int,set<int>>adj;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int res = a[i]+i-1;
        adj[res].insert(i);
    }
    map<int,bool> visited;
    dfs(n, adj,visited);
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
