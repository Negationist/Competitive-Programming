#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int dfs(int cur, int score, vector<int> &adj, vector<int> &val, vector<bool> &visited, int mx, int k){
    if(visited[cur] == true || k==0) return mx;
    visited[cur] = true;
    int fscore = score+k*val[cur];
    mx = max(mx, fscore);
    score+=val[cur];
    k--;
    return dfs(adj[cur], score, adj, val, visited, mx,k);
}

void solve(){
    int n,k,pB,pS;
    cin >> n >> k >> pB >> pS;
    pB--;
    pS--;
    vector<int> adj(n);
    vi val(n);
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        z--;
        adj[i] = z;
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    int ansB = dfs(pB, 0, adj, val, visited, -1, k);
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    int ansS = dfs(pS,0, adj, val,visited, -1, k);
    if(ansB > ansS){
        cout << "Bodya\n";
    } else if(ansS > ansB){
        cout << "Sasha\n";
    } else{
        cout << "Draw\n";
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
