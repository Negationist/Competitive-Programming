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
    int n,k;
    cin >> n >> k;
    vi r(n);
    for(int i=0;i<n;i++){
        cin >> r[i];
    }
    int ans = inf;
    vector<vi> dp(n,vi(k,inf));
    for(int i=0;i<n;i++){ //fix the starting door
        dp.assign(n,vi(k,inf));
        dp[i][0] = 0;
        for(int j=1;j<n;j++){
            dp[i][0]+=(r[(i+j)%n]*(j));
        }
        ans = min(ans,dp[i][0]);
        // cout << "base for " << i+1 << " is " << dp[i][0] << "\n";
        for(int j=1;j<n;j++){ //cur
            for(int l=1;l<k;l++){ //num door
                int cur = (i+j)%n;
                int savings = 0;
                int pref = 0;
                for(int m=0;(m+cur)%n!=i;m++){
                    pref+=r[(m+cur)%n];
                }
                //cout << "on " << cur+1 << " base savings are " << savings << " and pref is " << pref << "\n";
                for(int m=j-1;m>=0;m--){
                    savings+=pref;
                    dp[cur][l] = min(dp[cur][l],dp[(i+m)%n][l-1]-savings);
                    ans = min(dp[cur][l],ans);
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cbarn2.in","r",stdin);
    freopen("cbarn2.out", "w", stdout);
    solve();
    return 0;
}
