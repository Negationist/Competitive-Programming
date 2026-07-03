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
    int a[n], z[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        z[i] = a[i];
    }
    sort(a,a+n);
    int pref[n+1];
    pref[0] = 0;
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i]+a[i];
    }
    int dp[n];
    dp[n-1] = n-1;
    map<int,int> m;
    m[a[n-1]] = n-1;
    for(int i=n-2;i>=0;i--){
        if(pref[i+1] >= a[i+1]){
            dp[i] = dp[i+1];
        } else{
            dp[i] = i;
        }
        m[a[i]] = dp[i];
    }
    for(int i=0;i<n;i++){
        cout << m[z[i]] << " ";
    }
    cout << "\n";
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
