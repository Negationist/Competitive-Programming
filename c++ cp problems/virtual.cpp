#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define sz(x) (int)(x.size())

using ll = long long;

const ll maxN = 1e2;
const ll M = 998244353;
ll power(ll x, ll y)
{
    if(y == 0) return 1;
    ll p = power(x, y/2) % M;
    p = (p*p) % M;
    return (y%2==0) ? p: (x * p) % M;
}

ll modinv(ll x){
    return power(x,M-2);
}

signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll ans[maxN+5];
    ans[1] = 1;
    for(int i=2;i<=maxN;i++){
        ll p = ((((i*i)%M+i)%M)*modinv((2*i*i)%M))%M;
        ans[i] = ((p*i)%M + ((1-p+M)%M)*ans[i-1])%M;
    }
    int t;
    cin >> t;
    while(t--){
        int z;
        cin >> z;
        cout << ans[z] << "\n";
    }
    cout << (31LL*modinv(12))%M << "\n";
}