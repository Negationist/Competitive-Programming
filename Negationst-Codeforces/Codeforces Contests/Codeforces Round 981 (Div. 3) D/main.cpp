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
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int good[n];
    for(int i=0;i<n;i++){
        good[i] = -1;
    }
    int pref[n+1];
    pref[0] = 0;
    map<int,set<int>>m;
    m[0].insert(0);
    for(int i=1;i<n+1;i++){
        pref[i] = pref[i-1]+a[i-1];
        if(m[pref[i]].size()){
            int last = *(m[pref[i]].rbegin());
            if(good[last]==-1){
                good[last] = i;
            } else if(good[last]-last > good[last]-i){
                good[last] = i;
            }
        }
        m[pref[i]].insert(i);
    }
    for(int i=0;i<n;i++){
        good[i]--;
    }
    int dp[n+1] = {};
    for(int i=0;i<n;i++){
        if(i>0) dp[i] = max(dp[i],dp[i-1]);
        if(good[i]<0) continue;
        int next = good[i]+1;
        dp[next] = max(dp[next],dp[i]+1);
    }
    int ans = -1;
    for(int i=0;i<n+1;i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";
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
