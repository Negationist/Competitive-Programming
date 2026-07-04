#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int mod = 998244353;
const int maxN = 550;
ll fact[maxN], factInv[maxN];

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
    int res = fact[n]*factInv[n-r];
    res%=mod;
    res = res*factInv[r];
    res%=mod;
    return res;
}

void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vi> dp(n+1,vi(k+1,0));
    dp[n][0] = 1;
    for(int i=1;i<=k;i++){
        dp[n][i] = 0;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            for(int l=0;l<=j;l++){
                i128 res = (s[i]=='0'?nCr(j/2+(j&1),l):nCr(j/2,l))*dp[i+1][j-l];
                res%=mod;
                dp[i][j]+=res;
                dp[i][j]%=mod;
            }
        }
    }
    cout << dp[0][k] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
