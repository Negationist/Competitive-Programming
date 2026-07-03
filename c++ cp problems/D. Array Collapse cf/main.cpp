#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 998244353;
void solve(){
    int n;
    cin >> n;
    vector<int> last(n+1,-1);
    stack<int> s;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=n;i>=1;i--){
        while(s.size() && a[i]< a[s.top()]){
            last[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    vi dp(n+1);
    vi pref(n+1);
    vi sumdp(n+1);
    pref[1] = 1;
    dp[1] = 1;
    sumdp[1] = 1;
    for(int i=2;i<=n;i++){
        if(last[i]!=-1){
            dp[i] = (pref[i-1]-pref[last[i]]+sumdp[last[i]]+mod)%mod;//append to bigger elements
            sumdp[i] = (dp[i]+sumdp[last[i]])%mod;
            pref[i] = (pref[i-1]+dp[i])%mod;
        } else{
            dp[i] = (pref[i-1]+1)%mod;
            sumdp[i] = dp[i]%mod;
            pref[i] = (pref[i-1]+dp[i])%mod;
        }
    }
    int mn = LLONG_MAX;
    int ans = 0;
    for(int i=n;i>=1;i--){
        mn = min(mn,a[i]);
        if(a[i]==mn){
            ans = (ans+dp[i])%mod;
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
