#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(n==1) cout << 1 << "\n";
    else if (n==2) cout << 2*(s[0]!=s[1]);
    vector<vi> dp(n,vi(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        if(i+1<n) dp[i][i+1] = (s[i]==s[i+1] ? 0 : 2);
    }
    for(int j=2;j<n;j++){
        for(int i=0;i+j<n;i++){
            int k = i+j;
            dp[i][k] = 1+dp[i+1][k];
            for(int l=i+1;l<=k;l++){
                if(s[i]==s[l]){
                    int res = dp[i+1][l-1];
                    if(l!=k) res+=dp[l+1][k];
                    dp[i][k] = min(dp[i][k],res);
                }
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
