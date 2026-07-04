#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int mod = 1e9+7;
const int z= 2*1e5+5;
vector<int> fact(z);
void factorial(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<z;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=mod;
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

int modInv(int a, int mod){
    return binPowMod(a,mod-2,mod);
}

int nCr(int n,int r){
    int res = fact[n];
    res*=modInv(fact[n-r],mod);
    res%=mod;
    res*=modInv(fact[r],mod);
    res%=mod;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi a(n),p(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    int cnt[10] = {};
    vii probNo(10,1);
    for(int j=0;j<10;j++){
        bool found = false;
        for(int i=0;i<n;i++){
            if(a[i]&(1<<j)){
                (probNo[j].ff)*=(1e4-p[i]);
                (probNo[j].ss)*=(1e4);
            }
        }
    }
    for(int i=1;i<1023;i++){
        int sqaure = i*i;
        for(int j=0;j<10;j++){
            if(i&(1<<j)){

            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    factorial();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
