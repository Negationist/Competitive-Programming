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
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -inf));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int res = (text1[i]==text2[j]);
                if(i>0 && j>0){
                    res+=dp[i-1][j-1];
                }
                dp[i][j] = res;
                if(i>0){
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
                if(j>0){
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

void solve(){

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
