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
    sort(b.begin(),b.end(),greater<int>());
    int m = b.size();
    vector<vii> dp(m, vii(k,{-inf,inf}));
    vector<int> top(k,-inf);
    dp[0][0] = {0,0};
    top[(b[0]%k)] = b[0];
    if(mx>1){
        dp[0][(b[0]%k)] = {b[0],1};
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<k;j++){
            dp[i][j] = dp[i-1][j];
        }
        int mod = b[i]%k;
        for(int j=0;j<k;j++){
            int cur = (mod+j)%k;
            int res = dp[i-1][j].ff+b[i];
            if(res>dp[i][cur].ff && dp[i-1][j].ss<mx){
                if(dp[i-1][j].ss+1<mx){
                    dp[i][cur].ff = res;
                    dp[i][cur].ss = dp[i-1][j].ss+1;
                } else{
                    top[cur] = max(top[cur],res);
                }
            }
        }
    }
    vi ans(k);
    for(int i=0;i<k;i++){
        ans[i] = max(top[i],dp[m-1][i].ff);
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
