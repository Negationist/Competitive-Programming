#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int dfs(vector<vi> &adj, int cur, int p){
    int num =  adj[cur].size()-1;
    if(num==0 && cur!=0){
        return 0;
    }
    int mx = -1;
    for(int x : adj[cur]){
        if(x==p) continue;
        mx = max(mx,dfs(adj,x,cur));
    }
    int ans = mx;
    if(num<=2){
        ans+=1;
    } else{
        int inc = 31-__builtin_clz(num)+1-(__builtin_popcount(num)==1);
        ans+=inc;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=1;i<n;i++){
        int z;
        cin >> z;
        z--;
        adj[z].pb(i);
        adj[i].pb(z);
    }
    cout << dfs(adj,0,-1) << "\n";
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
