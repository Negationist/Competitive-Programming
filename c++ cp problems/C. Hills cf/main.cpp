#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<60;
void solve(){
    int n;
    cin >> n;
    int k = (n+1)/2;
    vi a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<vi> dp(n+1,vi(k+1));
    vi mn(k+1,inf);
    for(int i=1;i<=n;i++){
        if(i>=4){
            for(int j=1;j<=k;j++){
                mn[j] = min(mn[j],dp[i-3][j]);
            }
        }
        for(int j=0;j<=k;j++){
            if(!j){
                dp[i][j] = 0;
            } else if (j>(i+1)/2){
                dp[i][j] = inf;
            } else if(j==1){
                dp[i][j] = 0;
                if(i>1){
                    if(a[i]<=a[i-1]){
                        dp[i][j]+=(a[i-1]-a[i]+1);
                    }
                }
                if(i<n){
                    if(a[i]<=a[i+1]){
                        dp[i][j]+=(a[i+1]-a[i]+1);
                    }
                }
            } else{
                int res1 = dp[i-1][j];
                int res2 = inf;
                if(i>=3){
                    res2 = dp[i-2][j-1];
                    if(a[i]<a[i-2]){
                        int hill = a[i-2]-1;
                        if(hill>=a[i]){
                            res2+=(hill-a[i]+1);
                        }
                    }
                }
                int res3 = inf;
                if(i>=4){
                    res3 = mn[j-1];
                }
                if(a[i]<=a[i-1]){
                    res3+=(a[i-1]-a[i]+1);
                }
                dp[i][j] = min(res1,min(res2,res3));
                if(i!=n){
                    dp[i][j]+=(a[i]<=a[i+1] ? a[i+1]-a[i]+1 : 0);
                }
            }
        }
    }
    vi ans(k+1,inf);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            ans[j] = min(ans[j],dp[i][j]);
        }
    }
    for(int i=1;i<=k;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
