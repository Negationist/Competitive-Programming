#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int maxN = 3e5+5;
const int mod = 1e9+7;
int freq[maxN] = {};
int cnt[maxN] = {};
int fact[maxN];

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

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

int nCr(int n, int r){
    int res = fact[n]*modInv(fact[n-r],mod);
    res%=mod;
    res = res*modInv(fact[r],mod);
    res%=mod;
    return res;
}

void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        ++freq[z];
    }
    for(int i=1;i<maxN;i++){
        for(int j=i;j<maxN;j+=i){
            cnt[i]+=freq[j];
        }
    }
    int dp[8][maxN];
    for(int i=7;i>=1;i--){
        for(int j=maxN-1;j>=1;j--){
            if(cnt[j]<i){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = nCr(cnt[j],i);
            for(int k=2;k*j<maxN;k++){
                dp[i][j]-=dp[i][k*j];
                if(dp[i][j]<0){
                    dp[i][j]+=mod;
                }
            }
        }
    }
    for(int i=1;i<8;i++){
        if(dp[i][1]!=0){
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
