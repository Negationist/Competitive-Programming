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

void solve(){
    int n,x;
    cin >> n >> x;
    vi a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vi pref(n+1);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+a[i];
    }
    int ans = n*(n+1)/2;
    vi dp(n+2);
    dp[n+1] = 0;
    dp[n] = (a[n]>x);
    for(int i=n-1;i>=1;i--){
        if(pref[n]-pref[i-1]<=x){
            dp[i] = 0;
            continue;
        }
        int l = i, r = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(pref[mid]-pref[i-1]>x){
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        dp[i] = 1+dp[l+1];
    }
    for(int i=0;i<=n;i++){
        //cout << "dp " << i << " is " << dp[i] << "\n";
        ans-=dp[i];
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
