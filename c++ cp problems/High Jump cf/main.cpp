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
using u128 = unsigned __int128;
using i128 = __int128;
void solve(){
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<double> p(n+1),dp(n+1),t(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    dp[n] = p[n]*n, t[n] = 1e12;
    vi s; s.pb(n);
    for(int i=n-1;i>0;i--){
        int lo = 0, hi = s.size()-1, best = 1e12;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(t[s[mid]]>=i){
                best = min(best,s[mid]);
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        dp[i] = p[i]*(i-i*p[best]+dp[best]);
        while(s.size()){
            int cur = s.back();
            double t_new = (dp[i]-dp[cur])/((p[i]-p[cur]));
            if(t_new>=t[cur]){
                s.pop_back();
            } else{
                s.pb(i);
                t[i] = t_new;
                break;
            }
        }
    }
    double ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
