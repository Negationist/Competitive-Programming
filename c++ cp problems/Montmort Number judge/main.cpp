#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int mod;
const int maxN = 1e6+5;
vector<int> fact(maxN);
vector<int> inv(maxN);

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


void make(){
    fact[0] = 1;
    for(int i=1;i<maxN;i++) fact[i] = (fact[i-1]*i)%mod;
    inv[maxN-1] = modInv(fact[maxN-1],mod);
    for(int i=maxN-2;i>=1;i--){
        inv[i] = (inv[i+1]*(i))%mod;
    }
}

void solve(){
    int n;
    cin >> n >> mod;
    make();
    int c = 0;
    for(int i=1;i<=n;i++){

    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
