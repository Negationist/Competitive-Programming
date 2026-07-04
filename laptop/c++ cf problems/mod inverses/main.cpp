#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

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
    cout << (19*13)%17;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
