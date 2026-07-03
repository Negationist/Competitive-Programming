#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi dp(n,1LL<<60);
    dp[0] = 0;
    for(int i=0;i<n-1;i++){
        if(i<=n-2){
            dp[i+2] = min(dp[i+2],dp[i]+abs(a[i]-a[i+2]));
        }
        if(i<=n-1){
            dp[i+1] = min(dp[i+1],dp[i]+abs(a[i]-a[i+1]));
        }
    }
    cout << dp[n-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
