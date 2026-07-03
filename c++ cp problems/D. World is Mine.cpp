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
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int inf = 1e15;

void solve(){
    int n;
    cin >> n;
    vector<vi> dp(n+1,vi(n+1));
    vi num(n+1,0);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        num[z]++;
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        dp[0][i] = -inf;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = (j?max(dp[i-1][j]+(num[i]>0),(dp[i-1][j-1]-num[i]>=0?dp[i-1][j-1]-num[i]:-inf)):dp[i-1][0]+(num[i]>0));
            //cout << "dp [" << i << "] [" << j << "] is " << dp[i][j] << "\n";
        }
    }
    int ans = 0;
    for(int i=n;i>=0;i--){
        if(dp[n][i]>=0){
            ans = -i;
            break;
        }
    }
    cout << ans+n << "\n";
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