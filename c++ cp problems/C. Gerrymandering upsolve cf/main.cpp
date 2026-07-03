#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int vote(char x, char y, char z){
    int res = 0;
    res+=(x=='A'?1:0);
    res+=(y=='A'?1:0);
    res+=(z=='A'?1:0);
    return (res>1);
}

void solve(){
    int n;
    cin >> n;
    string s[2];
    for(int i=0;i<2;i++){
        cin >> s[i];
        s[i] = "+"+s[i];
    }
    vector<vector<int>> dp(n+10,vector<int>(3,-1));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(dp[i][j]==-1) continue;
            if(j==0){
                dp[i+3][0] = max(dp[i+3][0], dp[i][0] + vote(s[0][i+1],s[0][i+2],s[0][i+3]) + vote(s[1][i+1],s[1][i+2],s[1][i+3]));
                dp[i+1][1] = max(dp[i+1][1], dp[i][0] + vote(s[0][i+1],s[1][i+1],s[0][i+2]));
                dp[i+1][2] = max(dp[i+1][2], dp[i][0] + vote(s[0][i+1],s[1][i+1],s[1][i+2]));
            } else if(j==1){
                dp[i+3][1] = max(dp[i+3][1], dp[i][1]+vote(s[0][i+2],s[0][i+3],s[0][i+4])+vote(s[1][i+1],s[1][i+2],s[1][i+3]));
                dp[i+2][0] = max(dp[i+2][0], dp[i][1]+vote(s[1][i+1], s[1][i+2], s[0][i+2]));
            } else{
                dp[i+3][2] = max(dp[i+3][2], dp[i][2]+vote(s[0][i+1],s[0][i+2],s[0][i+3])+vote(s[1][i+2],s[1][i+3],s[1][i+4]));
                dp[i+2][0] = max(dp[i+2][0], dp[i][2]+vote(s[0][i+1], s[0][i+2], s[1][i+2]));
            }
        }
    }
    cout << dp[n][0] << "\n";
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
