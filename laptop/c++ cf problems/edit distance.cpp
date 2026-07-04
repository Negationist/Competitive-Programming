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
    //string word1, word2;
    //cin >> word1 >> word2;
    int n1 = word1.size(), n2 = word2.size();
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(j==0){
                dp[i][j] = i;
            } else if(i==0){
                dp[i][j] = j;
            } else{
                dp[i][j] = min({dp[i][j-1]+1,dp[i-1][j-1]+1,dp[i-1][j]+1, (word1[i-1]==word2[j-1]?dp[i-1][j-1]:100000)});
            }
        }
    }
    //cout <<  dp[n1][n2];
    return dp[n1][n2];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}