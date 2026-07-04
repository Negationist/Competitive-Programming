#include <bits/stdc++.h>
#define int long long
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
    int n,m;
    cin >> n >> m;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
        dp[i]%=m;
    }
    for(int i=1;i<=n;i++){
        cout << dp[i] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
