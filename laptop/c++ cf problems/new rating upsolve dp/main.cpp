#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int f(int x, int a){
    if(x>a){
        return --x;
    } else if(x<a){
        return ++x;
    }
    return x;
}

void input(vi &a){
    int n = a.size();
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    input(a);
    vector<vi> dp(n,vi(3));
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = -1LL<<30;
    for(int i=1;i<n;i++){
        dp[i][0] = f(dp[i-1][0],a[i]);
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][2] = max(f(dp[i-1][1],a[i]),f(dp[i-1][2],a[i]));
    }
    cout << max(dp[n-1][1],dp[n-1][2]) << "\n";
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
