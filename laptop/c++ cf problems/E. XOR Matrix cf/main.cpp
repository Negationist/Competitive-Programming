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
const int mod = 998244353;

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
    ll ans = a*b;
    ll res1 = (a+1)*a*b*binPowMod(2,n-1,mod);
    ll res2 = a*(b+1)*b*binPowMod(2,m-1,mod);
    ans+=res1; ans%=mod;
    ans+=res2; ans%=mod;
    for(int i=0;i<29;i++){
        int f1,f2;
        int dp1[30][2],dp2[30][2];
        dp1[29][0] = dp2[29][0] = 1;
        dp2[29][1] = dp2[29][1] = 0;
        for(int j=28;j>=0;j--){
            if(j==i){
                dp1[j][0] = (n&(1LL<<j)?1:0);
                dp2[j][0] = (m&(1LL<<j)?1:0);
                dp1[j][1] =
            } else{
                dp1[j][0] = dp1[j+1][0];
                dp1[j][1] = 2*dp1[j+1][1]+(n&(1LL<<j)?dp[j+1][0]:0);
                dp2[j][0] = dp2[j+1][0];
                dp2[j][1] = 2*dp2[j+1][1]+(m&(1LL<<j)?dp[j+1][0]:0);
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
    while(t--){
        solve();
    }
    return 0;
}
