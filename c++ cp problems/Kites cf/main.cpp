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
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int dp[n-1];
    int mn = 1LL<<50;
    int ans = 1LL<<50;
    for(int i=0;i<n-1;i++){
        int diff = a[i+1]-a[i];
        dp[i] = mn+diff;
        ans = min(ans,dp[i]);
        if(i){
            mn = min(mn,a[i]-a[i-1]);
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
