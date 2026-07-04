#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int dp[n+1];
    string s;
    cin >> s;
    dp[n] = 0;
    for(int i=n-1;i>=0;i--){
        if (s[i]=='W'){
            dp[i] = 1+dp[i+1];
        } else if (s[i]=='L'){
            for(int j=i+1;j<i+1+m;j++){
                if(j>n+1) break;
                if(j==i+1) {
                    dp[i] = dp[j];
                    continue;
                }
                dp[i] = min(dp[i],dp[j]);
            }
        } else{
            dp[i] = 200001;
        }
    }
    if (dp[0]<=k){
        cout << "YES";
    } else{
        cout << "NO" << endl;
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
