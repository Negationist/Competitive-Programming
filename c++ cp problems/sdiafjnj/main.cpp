#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
const int mod = 1e9+7;
const int maxN = 105;
ll fact[maxN],factInv[maxN];

ll binPowMod(ll b, int p, int mod){
    ll res = 1;
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

ll modInv(ll x, int mod){
    return binPowMod(x,mod-2,mod);
}

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    factInv[maxN-1] = modInv(fact[maxN-1],mod);
    for(int i=maxN-2;i>=0;i--){
        factInv[i] = (factInv[i+1]*(i+1))%mod;
    }
}

int nCr(int n, int r){
    if(n<r) return 0;
    ll res = fact[n]*modInv(fact[n-r],mod);
    res%=mod;
    res = res*modInv(fact[r],mod);
    res%=mod;
    return res;
}

int starbar(int n, int k){
    if(!k) return 1;
    return nCr(n+k-1,k-1);
}

void solve(){
    int n,c,m;
    cin >> n >> c >> m;
    int dp[m+1][n+1] = {};
    int sum[m+1][n+1] = {};
    dp[c][n] = 1;
    for(int i=1;i<=n;i++){
        sum[c][i] = 1;
    }
    for(int i=c+1;i<=m;i++){
        for(int j=n-1;j>=1;j--){
            for(int k=1;k<=c;k++){
                ll res = sum[i-k][j+1]*starbar(k,c-k+1);
                dp[i][j] = (res+dp[i][j])%mod;
            }
            sum[i][j] = (sum[i][j+1]+dp[i][j])%mod;
        }
    }
    cout << sum[m][1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    compute();
    while(t--){
        solve();
    }
    return 0;
}
