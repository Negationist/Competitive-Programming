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
using ld = long double;
const int mod = 998244353;
const int maxN = 5e5+10;
int fact[maxN],factInv[maxN];

ll binPowMod(ll b, ll p, ll mod){
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

ll modInv(ll x, ll mod){
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

void solve(){
    vi l(13),r(13);
    int sum = 0;
    for(int i=0;i<13;i++){
        cin >> l[i];
        sum+=l[i];
    }
    for(int i=0;i<13;i++){
        cin >> r[i];
        sum+=r[i];
    }
    int target = sum/2;
    int one = fact[sum/2]*fact[(sum/2)+(sum&1)];
    one%=mod;
    for(int i=0;i<13;i++){
        one = (one*factInv[l[i]])%mod;
    }
    for(int i=0;i<13;i++){
        one = (one*factInv[r[i]])%mod;
    }
    map<int,int> cntl, cntr;
    int maskl[(1LL<<13)];
    maskl[0] = 0;
    for(int i=1;i<(1LL<<13);i++){
        int msb = 63-__builtin_clzll(i);
        maskl[i] = maskl[i-(1LL<<msb)]+l[msb];
        if(l[msb]==0 || maskl[i-(1LL<<msb)]==-1) maskl[i] = -1;
        if(maskl[i]!=-1){
            cntl[maskl[i]]++;
        }
    }
    int maskr[(1LL<<13)];
    maskr[0] = 0;
    for(int i=1;i<(1LL<<13);i++){
        int msb = 63-__builtin_clzll(i);
        maskr[i] = maskr[i-(1LL<<msb)]+r[msb];
        if(r[msb]==0 || maskr[i-(1LL<<msb)]==-1) maskr[i] = -1;
        if(maskr[i]!=-1){
            cntr[maskr[i]]++;
        }
    }
    int num = 0;
    cntl[0] = 1;
    cntr[0] = 1;
    for(auto x : cntl){
        int goal = target-x.ff;
        num+=(x.ss*cntr[goal]);
    }
    int ans = (one*num)%mod;
    cout << ans << "\n";
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
