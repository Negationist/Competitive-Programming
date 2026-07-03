#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
const int mod = 998244353;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int dp[n][3];
    dp[0][0] = (a[0]==1?1:0);
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]+(a[i]==1?1:0);
        dp[i][1] = dp[i-1][1]+(a[i]==2?dp[i-1][0]+dp[i-1][1]:0);
        dp[i][2] = dp[i-1][2]+(a[i]==3?dp[i-1][1]:0);
        dp[i][0]%=mod;
        dp[i][1]%=mod;
        dp[i][2]%=mod;
    }
    cout << dp[n-1][2] << "\n";
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
