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
    int n,m,ans=-1;
    cin >> n >> m;
    vector<vector<int>> dp(2, vector<int> (m+3,0));
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int b[m+3];
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cnt++;
            dp[i%2][0] = dp[(i+1)%2][0];
            for(int j=1;j<=cnt;j++){
                dp[i%2][j] = max(dp[(i+1)%2][j-1], dp[(i+1)%2][j]);
            }
            continue;
        }
        for(int j=0;j<=cnt;j++){
            if(a[i]<0){
                int high
            } else{
                dp[i%2][j] = dp[(i+1)%2][j] + (a[i]<=j);
            }
            ans = max(ans, dp[i%2][j]);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
