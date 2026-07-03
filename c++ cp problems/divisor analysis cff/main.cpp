#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int MOD = 1e9+7;

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
    int num=1, sum = 1, prod=1;
    int cnt = 1;
    for(int i=0;i<n;i++){
        int b,p;
        cin >> b >> p;
        num*=(p+1);
        num%=MOD;
        cnt*=(p+1);
        cnt%=(MOD-1);
        prod*=binPowMod(b,p,MOD);
        prod%=MOD;
        int res = -(1-binPowMod(b,p+1,MOD))*modInv(b-1,MOD);
        res%=MOD;
        sum*=res;
        sum%=MOD;
    }
    int real = prod;
    prod = binPowMod(prod, cnt/2,MOD);
    if(cnt%2==1){
        prod = prod*sqrtl(real);
        prod%=MOD;
    }
    cout << num << " " << sum << " " << prod << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
