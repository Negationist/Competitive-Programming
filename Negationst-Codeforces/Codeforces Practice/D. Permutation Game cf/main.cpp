#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int dfs(int cur, int score, vector<int> adj, vector<int> score, vector<int> &visited, int mx, int k){
    int curScore = score +
    k--;
}

void solve(){
    int n,k,pB,pS;
    cin >> n >> k >> pB >> pS;
    vector<vi> adj;
    vi score(n);
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        adj[z].pb(i);
        adj[i].pb(z);
    }
    for(int i=0;i<n;i++){
        cin >> score[i];
    }
    int ansB = dfs(pB, 0, adj, score,visited, -1, k);
    int ansS = dfs(pS,0, adj, score,visited, -1, k);
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
