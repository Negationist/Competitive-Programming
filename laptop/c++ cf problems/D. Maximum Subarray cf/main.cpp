#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
const int inf = 1LL<<60;
void solve(){
    int n,k,x;
    cin >> n >> k >> x;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<vi> dp(n+1,vi(k+1));
    dp[0][0] = 0;
    for(int i=1;i<=k;i++){
        dp[0][1] = -inf;
    }
    for(int i=1;i<=n;i++){
        int mn = k-(n-i);
        for(int j=0;j<=k;j++){
            if(j<mn || j>i){
                dp[i][j] = -inf;
            } else{
                if(!j){
                    dp[i][0] = max(dp[i-1][0]+a[i]-x,0LL);
                } else{
                    dp[i][j] = max(dp[i-1][j-1]+a[i]+x, dp[i-1][j]+a[i]-x);
                    dp[i][j] = max(dp[i][j],0LL);
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            ans = max(ans,dp[i][j]);
        }
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
