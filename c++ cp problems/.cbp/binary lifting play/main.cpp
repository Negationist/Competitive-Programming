#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int mxD;
int root = 0;
void dfs(int cur, int parent, vector<vi>&up, vector<vi>&adj){
    up[cur][0] = parent;
    for(int i=1;i<=mxD;i++){
        if(up[cur][i-1]!=-1) up[cur][i] = up[up[cur][i-1]][i-1];
    }
    for(int x : adj[cur]){
        if(x!=parent){
            dfs(x,cur,up,adj);
        }
    }
}
int kthA(int x, int k, vector<vi>&up){
    while(k>0){
        if(x==-1) break;
        int jump = 32-__builtin_clz(k);
        jump--;
        x = up[x][jump];
        k-=(1<<jump);
    }
    return max(x,root);
}

void solve(){
    int n,q;
    cin >> n >> q;
    vector<vi>adj(n);
    mxD = 32-__builtin_clz(n);
    vector<vi> up(n,vi(mxD+1,-1));
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1, up,adj);
    //preprocessing for binary lift(only thing it couldnt lift is yo mama)
    while(q--){

    }
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
