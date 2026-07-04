#include <bits/stdc++.h>
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
    int n,q;
    cin >> n >> q;
    vector<vector<vi>> dp(3, vector<vi>(n,vi(n,n)));
    int ans = 0;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        ans+=(!(--dp[0][a][b]));
        ans+=(!(--dp[1][b][c]));
        ans+=(!(--dp[2][a][c]));
        cout << ans << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
