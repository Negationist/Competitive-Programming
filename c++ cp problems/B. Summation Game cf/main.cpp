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
    int n,k,x;
    cin >> n >> k >> x;
    int a[n],sum[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    sum[0] = 0;
    for(int i=0;i<n;i++){
        sum[i+1] = sum[i]+a[i];
    }
    int ans  = LLONG_MIN;
    for(int i=0;i<=k;i++){
        int take = sum[n-i] - sum[max(n-i-x,0LL)];
        int give = sum[max(n-i-x,0LL)];
        ans = max(ans, give-take);
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
