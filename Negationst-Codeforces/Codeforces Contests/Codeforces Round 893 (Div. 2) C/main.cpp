#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void dfs(int cur,vector<vi> &adj,set<int> &s){
    s.erase(cur);
    cout << cur << " ";
    for(int x : adj[cur]){
        dfs(x, adj,s);
    }
}

using namespace std;

void solve(){
    int n;
    cin >> n;
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    vector<vi> adj(n+1);
    for(int i=2;i<=n/2;i++){
        adj[i].pb(2*i);
    }
    while(s.size()){
        dfs(*s.begin(),adj,s);
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
