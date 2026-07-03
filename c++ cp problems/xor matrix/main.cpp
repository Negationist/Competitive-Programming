#include <bits/stdc++.h>
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
const ll mod = 998244353;

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

void solve(){
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    ++a; ++b;
    ll ans = a*b;
    ll res1 = (((a-1)*a)/2)%mod;
    res1 = (res1*b)%mod;
    res1 = (res1*(binPowMod(2,n,mod)-2+mod))%mod;
    ll res2 = (((b-1)*b)/2)%mod;
    res2 = (res2*a)%mod;
    res2 = (res2*(binPowMod(2,m,mod)-2+mod))%mod;
    ans+=res1; ans%=mod;
    ans+=res2; ans%=mod;
    ll ways = binPowMod(2,n+m,mod)-binPowMod(2,n+1,mod)-binPowMod(2,m+1,mod)+4;
    ways = (ways+10*mod)%mod;
    for(int i=0;i<29;i++){
        ll dp1[30][2],dp2[30][2];
        dp1[29][0] = dp2[29][0] = 1;
        dp1[29][1] = dp2[29][1] = 0;
        for(int j=28;j>=0;j--){
            if(j==i){
                dp1[j][0] = ((a-1)&(1LL<<j)?1:0);
                dp2[j][0] = ((b-1)&(1LL<<j)?1:0);
                dp1[j][1] = dp1[j+1][1];
                dp2[j][1] = dp2[j+1][1];
            } else{
                dp1[j][0] = dp1[j+1][0];
                dp1[j][1] = 2*dp1[j+1][1]+((a-1)&(1LL<<j)?dp1[j+1][0]:0);
                dp2[j][0] = dp2[j+1][0];
                dp2[j][1] = 2*dp2[j+1][1]+((b-1)&(1LL<<j)?dp2[j+1][0]:0);
            }
        }
        ll f1 = (dp1[0][0]+dp1[0][1])%mod, f2 = (dp2[0][0]+dp2[0][1])%mod;
        ll res3 = binPowMod(2,i,mod);
        res3 = (res3*f1)%mod;
        res3 = (res3*f2)%mod;
        res3 = (res3*ways)%mod;
        ans = (ans+res3)%mod;
    }
    cout << ans << "\n";
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
