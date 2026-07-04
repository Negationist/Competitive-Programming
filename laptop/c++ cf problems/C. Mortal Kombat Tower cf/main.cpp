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
    int n;
    cin >> n;
    vi a(n+1);
    a[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<vi> dp(n+1, vi(2,inf));
    dp[0][1] = 0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]+(a[i+1]==1));
            dp[i+1][1] = min(dp[i+1][1],dp[i][0]);
        } else{
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]+(a[i+1]==1));
            dp[i+2][0] = min(dp[i+2][0], dp[i][1]+(a[i+1]==1) + (a[i+2]==1));
            dp[i+1][1] = min(dp[i+1][1],dp[i][0]);
            dp[i+2][1] = min(dp[i+2][1],dp[i][0]);
        }
    }
    cout << min(dp[n][0],dp[n][1]) << "\n";
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
