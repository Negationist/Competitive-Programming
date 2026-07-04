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
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vi> dp(n, vi(m,inf));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int res = (s1[i]!=s2[j]);
            if(i>0 && j>0){
                res+=dp[i-1][j-1];
            }
            dp[i][j] = res;
            if(i>0){
                dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            }
            if(j>0){
                dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            }
        }
    }
    cout << dp[n-1][m-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
