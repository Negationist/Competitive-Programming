#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void dfs(int cur, int dis, bool &win,vector<vi> &adj, int last){
    if(adj[cur].size()==1 && dis>0){
        win = win | (dis%2==1);
        return;
    }
    for(int x : adj[cur]){
        if(x != last){
            dfs(x,dis+1,win,adj,cur);
        }
    }
}

void solve(){
    int n,t;
    cin >> n >> t;
    vector<vi> adj(n);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int z;
    cin >> z;
    z--;
    bool Ron = false;
    dfs(z,0,Ron,adj, -1);
    if(Ron){
        cout << "Ron\n";
    } else{
        cout << "Hermione\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
