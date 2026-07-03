#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++){
        if(i<7) dp[i]++;
        for(int j=1;j<=6 && i+j<=n;j++){
            dp[i+j]+=dp[i];
            dp[i+j]%=mod;
        }
    }
    cout << dp[n] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
