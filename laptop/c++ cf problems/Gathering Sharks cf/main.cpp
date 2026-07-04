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
    int n;
    cin >> n;
    vi pos(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        --z;
        pos[z] = i;
    }
    int dp[n][n];
    for(int k=0;k<n;k++){ //size
        for(int i=0;i<n;i++){ //start
            int j = i+k;
            if(j>n) continue;
            if(i==j) dp[i][j] = 0;
            else{
                dp[i][j] = inf;
                for(int l=j-1;l>=i;l--){
                    int res = dp[l][j-1]+dp[i][l]+abs(pos[l]-pos[j]);
                    dp[i][j] = min(res,dp[i][j]);
                }
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
