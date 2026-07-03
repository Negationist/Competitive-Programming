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
    int n,m,z;
    cin >> n >> m >> z;
    int dp[n][m][m] = {};
    int a[n][m];
    int mn[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(!i && !j){
                mn[i][j] = a[i][j];
            } else mn[i][j] = inf;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(!i && !j){
                    dp[i][j][k] = a[i][(j+k)%m]+z*k;
                } else dp[i][j][k] = inf;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j!=0){
                    dp[i][j][k] = min(dp[i][j][k],dp[i][j-1][k]+a[i][(j+k)%m]);
                }
                if(i!=0){
                    dp[i][j][k] = min(dp[i][j][k],mn[i-1][j]+a[i][(j+k)%m]+z*k);
                }
                mn[i][j] = min(dp[i][j][k],mn[i][j]);
            }
        }
    }
    int ans = inf;
    for(int i=0;i<m;i++){
        ans = min(ans,dp[n-1][m-1][i]);
    }
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
