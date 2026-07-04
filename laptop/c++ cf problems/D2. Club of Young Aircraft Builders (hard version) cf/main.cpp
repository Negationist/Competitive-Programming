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
const int maxN = 200;
int fact[maxN],factInv[maxN];
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
    int n,c,m;
    cin >> n >> c >> m;
    vi a(m);
    for(int i=0;i<m;i++) cin >> a[i];
    vector<vi> sum(n+1,vi(n+1,0));
    for(int j=1;j<=n;j++){
        for(int k=0;k<=1;k++){
            if(!k){
                sum[j][k] = 1;
            } else{
                sum[j][k] = n-j+1;
            }
        }
    }
    for(int i=2;i<=m;i++){
        vector<vi> dp(n+1,vi(n+1));
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(k>i){
                    dp[j][k] = 0;
                } else{
                    if(j==n){
                        dp[j][k] = nCr(i-1,k-1);
                    } else{
                        dp[j][k] = prefsum[j+1][k-1];
                    }
                }
            }
        }
    }
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
