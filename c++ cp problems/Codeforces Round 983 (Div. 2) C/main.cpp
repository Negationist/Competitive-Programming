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
    sort(a.begin(),a.end());
    int dp[n];
    dp[0] = dp[1] = 0;
    int l=0;
    for(int i=2;i<n;i++){
        while(a[l]+a[l+1]<=a[i]){
            l++;
        }
        dp[i] = l;
    }
    for(int i=0;i<n;i++){
        dp[i]+=(n-i-1);
    }
    int ans = LLONG_MAX;
    for(int i=0;i<n;i++){
        ans = min(ans,dp[i]);
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
