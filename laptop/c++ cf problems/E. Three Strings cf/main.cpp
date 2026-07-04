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
    string a,b,c;
    cin >> a >> b >> c;
    int n = a.size(); int m = b.size();
    vector<vi> dp(n+1, vi(m+1,inf));
    dp[0][0] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i<n){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]+(a[i]!=c[i+j]));
            }
            if(j<m){
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+(b[j]!=c[i+j]));
            }
        }
    }
    cout << dp[n][m] << "\n";
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
