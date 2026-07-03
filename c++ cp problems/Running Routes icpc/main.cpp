#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    int dp[n][n] = {};
    set<int> adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int z;
            cin >> z;
            if(z){
                adj[i].insert(j);
            }
        }
    }
    for(int z=1;z<n;z++){
        for(int i=0;i<n;i++){
            int j = (i+z)%n;
            dp[i][j] = dp[(i+1)%n][j];
            if(adj[i].find((i+1)%n)!=adj[i].end()){
                dp[i][j] = max(dp[i][j],1+(z>1?dp[(i+2)%n][j]:0));
            }
            if(adj[i].find(j)!=adj[i].end()){
                dp[i][j] = max(dp[i][j],1+(z>1?dp[(i+1)%n][(j-1)%n]:0));
            }
            if(z<3) continue;
            int x = (i+2)%n;
            while(x!=j){
                if(adj[i].find(x)!=adj[i].end()){
                    dp[i][j] = max(dp[i][j],1+dp[(i+1)%n][(x-1+n)%n]+dp[(x+1)%n][j]);
                }
                x = (x+1)%n;
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
