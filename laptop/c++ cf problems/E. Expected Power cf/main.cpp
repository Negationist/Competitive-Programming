#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
const int mod = 1e9+7;

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
    vii dp(1024);
    dp[0] = {1,1};
    for(int i=1;i<=1023;i++){
        dp[i] = {0,1};
    }
    vi a(n+1),p(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> p[i];
    auto prod = [&](pii a, pii b){
        pii res = {(a.ff*b.ff)%mod, (a.ss*b.ss)%mod};
        return res;
    };
    auto sum = [&](pii a, pii b){
        int top = ((a.ff*b.ss)+(a.ss*b.ff))%mod;
        pii res = {top, (a.ss*b.ss)%mod};
        return res;
    };
    for(int i=1;i<=n;i++){
        vii ndp(1024);
        for(int j=0;j<=1023;j++){
            pii res1 = prod(dp[j],{1e4-p[i],1e4});
            pii res2 = prod(dp[j^a[i]],{p[i],1e4});
            ndp[j] = sum(res1,res2);
        }
        dp = move(ndp);
    }
    for(int i=0;i<=1023;i++){
        dp[i].ff = (dp[i].ff*i*i)%mod;
    }
    pii ans = {0,1};
    for(int i=1;i<=1023;i++){
        ans = sum(ans,dp[i]);
    }
    int rans = (ans.ff*modInv(ans.ss,mod))%mod;
    cout << rans << "\n";
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
