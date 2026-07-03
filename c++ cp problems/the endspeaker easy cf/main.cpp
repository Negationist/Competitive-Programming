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
    int n,m;
    cin >> n >> m;
    vi a(n+1), b(m+1),pref(n+1);
    a[0] = b[0] = pref[0] = 0;
    for(int i=1;i<n+1;i++){
        cin >> a[i];
    }
    for(int i=1;i<m+1;i++){
        cin >> b[i];
    }
    for(int i=1;i<n+1;i++){
        pref[i] = pref[i-1]+a[i];
    }
    vector<vi> dp(n+1,vector<int>(m+1, LLONG_MAX));
    //dp i j is min cost to get to position i with k equal to j
    dp[0][1] = 0;
    for(int i=0;i<n+1;i++){
        for(int j=1;j<m;j++){
            dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
        }
        if(i==n) break;
        for(int j=1;j<m+1;j++){
            int l=i,r=n;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(pref[mid]-pref[i]<=b[j]){
                    l = mid + 1;
                } else r = mid-1;
            }
            if(dp[i][j]==LLONG_MAX) continue;
            dp[r][j] = min(dp[r][j],dp[i][j]+(m-j));
        }
    }
    cout << (dp[n][m]==LLONG_MAX?-1:dp[n][m]) << "\n";
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
