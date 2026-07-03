#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int inf = 1LL<<60;

void solve(){
    int n,m,c;
    cin >> n >> m >> c;
    vi a(n);
    vector<vi> adj(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
    }
    vector<vi> dp(n,vector<int> (2000, -inf));
    int ans = 0;
    dp[0][0] = 0;
    for(int i=0;i<1999;i++){
        for(int j=0;j<n;j++){
            for(int x : adj[j]){
                dp[x][i+1] = max(dp[x][i+1], dp[j][i]+a[x]);
            }
        }
    }
    for(int i=0;i<2000;i++) ans = max(ans, dp[0][i] - c*i*i);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("time.in","r",stdin);
    freopen("time.out", "w", stdout);
    solve();
    return 0;
}
