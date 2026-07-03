#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
vector<vector<int>> adj;
vector<int> cnt;
int mx = 0;
int node;

void dfs(int s, int e, int dis){
    if(dis>mx){
        mx = dis;
        node = s;
    }
    for(int x : adj[s]){
        if(x != e){
            dfs(x,s,dis+1);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    adj.assign(n,vector<int>());
    cnt.resize(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1,0);
    dfs(node,-1,0);
    cout << mx << endl;
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
