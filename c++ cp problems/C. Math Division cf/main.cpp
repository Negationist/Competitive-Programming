#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
const int mod = 1e9+7;
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
ll inv2;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for(int i=n-1;i>=1;i--){
        ans = (ans+(s[i]=='1'))*inv2;
        if(ans>mod){
            ans%=mod;
        }
    }
    cout << ans+n-1 << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    inv2 = modInv(2LL,mod);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
