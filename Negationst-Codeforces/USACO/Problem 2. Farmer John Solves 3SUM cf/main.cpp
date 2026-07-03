#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int mod = 998244353;

int binPowMod(int b, int p, int mod){
    int res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}

int modInv(int x, int mod){
    return binPowMod(x,mod-2,mod);
}


void solve(){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[0] = dp[1] = dp[2] = dp[3] = 0;
    for(int i=4;i<=n;i++){
        //dp i-3 is the number of ways to get to one inversion at size i-1, the
        //after that the sum is the sum from 3 to i-1
        dp[i] = i*(i-3)/2;
        dp[i]%=mod;
        //dp[i] is number of ways to get more than one inversion at size i
    }
    int ans = 0;
    int big = 1;
    for(int i=5;i<=n;i++){
        big*=i;
        big%=mod;
    }
    for(int i=4;i<n;i++){
        dp[i]*=big;
        big*=modInv(i+1,mod);
        big%=mod;
        ans+=dp[i];
        ans%=mod;
    }
    ans+=dp[n];
    ans%=mod;
    int res = 1+n-2; //add one and zeros inversions at the end size
    ans+=res;
    ans%=mod;
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
