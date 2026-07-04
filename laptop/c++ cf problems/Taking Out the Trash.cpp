#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,t,s,b;
    cin >> n >> t >> s >> b;
    int a[t];
    int dp[t][2];
    for(int i=0;i<t;i++) cin >> a[i];
    //dp[i][0] is best answer if you are decreasing at time i, 1 is best answer if you are increasing
    dp[0][0] = (s<=a[0]);
    dp[0][1] = (s>a[0]);
    for(int i=1;i<t;i++){
        if(a[i-1]<a[i]){ //neede to go up
            dp[i][1] = min(dp[i-1][1],dp[i-1][0]+1);
            dp[i][0] = min(dp[i-1][1]+1,dp[i-1][0]+2);
        } else if(a[i-1]>a[i]){ //needed to go down
            dp[i][1] = min(dp[i-1][1]+2,dp[i-1][0]+1);
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1);
        } else{
            dp[i][0] = min(dp[i-1][1]+1,dp[i-1][0]);
            dp[i][1] = min(dp[i-1][1],dp[i-1][0]+1);
        }
    }
    // for(int i=0;i<t;i++){
    //     cout << "dp " << i << " " << 0 << " is " << dp[i][0] << "\n";
    //     cout << "dp " << i << " " << 1 << " is " << dp[i][1] << "\n";
    // }
    int ans1 = dp[t-1][0]+(b>a[t-1]), ans2 = dp[t-1][1]+(b<=a[t-1]);
    cout << min(ans1,ans2) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}