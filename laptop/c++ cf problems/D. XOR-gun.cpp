#include <bits/stdc++.h>
#define int long long
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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(n>=100){
        cout << 1 << "\n";
    } else{
        int ans = 1e6;
        int dp[n][n] = {};
        for(int i=0;i<n;i++){
            dp[i][i] = a[i];
        }
        for(int k=1;k<n;k++){
            for(int i=0;i+k<n;i++){
                dp[i][i+k] = dp[i][i+k-1]^a[i+k];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                //cout <<"dp " << i << " " << j << " is " << dp[i][j] << "\n";
            }
        }
        for(int i=0;i+1<n;i++){
            for(int j=0;j<=i;j++){
                for(int k=i+1;k<n;k++){
                    //cout << "doing " << j << " " << i << " vs " << i+1 << " " << k << "\n";
                    if(dp[j][i]>dp[i+1][k]){
                        ans = min(ans,i-j+k-(i+1));
                    }
                }
            }
        }
        cout << (ans<1e6?ans:-1) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}