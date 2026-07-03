#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
const int mod = 1e9+7;
const int maxN = 200;
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

ll nCr(int n, int r){
    if(n<r) return 0;
    ll res = fact[n]*factInv[n-r];
    res%=mod;
    res = res*factInv[r];
    res%=mod;
    return res;
}

ll starbar(int n, int k){
    return nCr(n+k-1,k-1);
}

void solve(){
    int n,c,m;
    cin >> n >> c >> m;
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
    }
    int dp[m+3][n+3] = {};
    int sum[m+3][n+3] = {};
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
