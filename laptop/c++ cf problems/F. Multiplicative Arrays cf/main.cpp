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
const int maxN = 1e5+10;
const int mod = 998244353;
int sieve[maxN] = {};
int fact[maxN],factInv[maxN];

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
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
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
    int k,n;
    cin >> k >> n;
    cout << n << "\n";
    for(int i=2;i<=k;i++){
        map<int,int> cnt;
        int temp = k;
        int num = 0;
        while(temp>1){
            ++cnt[sieve[temp]];
            temp/=sieve[temp];
            ++num;
        }
        for(int i=1;i<=num;i++){
            int ways = 0;
            for(){
                //get ways
            }
            int num = binPowMod(2,n,mod);
            for(int j=0;j<i;j++){
                num = (num+mod-nCr())
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
