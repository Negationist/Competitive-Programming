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
vi get(vi b, int k, int mx){
    int m = b.size();
    vector<vector<vi>> dp(m+1,vector<vi>(k,vi(mx+1,-inf)));
    dp[0][0][0] = 0;
    vi ans(k,-inf);
    ans[0] = 0;
    for(int i=0;i<m;i++){
        int mod = b[i]%k;
        for(int j=0;j<k;j++){
            int cur = (j+mod)%k;
            for(int l=0;l<mx;l++){
                dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]);
                dp[i+1][cur][l+1] = max(dp[i+1][cur][l+1], dp[i][j][l]+b[i]);
                if(l+1<=mx){
                    ans[cur] = max(ans[cur],dp[i+1][cur][l+1]);
                }
            }
        }
    }
    return ans;
}

void solve(){
     int n,m,k;
     cin >> n >> m >> k;
     int mx = m/2;
     vector<vi> a(n,vi(m));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
     }
     if(mx==0){
        cout << 0 << "\n";
        return;
     }
     vector<vi> dp(n,vi(k));
     auto b = get(a[0],k,mx);
     for(int i=0;i<k;i++){
        dp[0][i] = b[i];
     }
     for(int i=1;i<n;i++){
        for(int j=0;j<k;j++) dp[i][j] = dp[i-1][j]; //base
        auto b = get(a[i],k,mx); //find maxes
        for(int j=0;j<k;j++){
            for(int l=0;l<k;l++){
                int mod = (j+l)%k;
                dp[i][mod] = max(dp[i][mod], dp[i-1][j]+b[l]);
            }
        }
     }
     cout << dp[n-1][0] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
