#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int mod = 998244353;

const int maxN = 100;
ll fact[maxN], factInv[maxN];

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
    int n;
    cin >> n;
    int r; cin >> r;
    vi a(n);
    int mx = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int mx_loss = 0, mxs = -1, o = 0;
    for(int i=0;i<n;i++){
        mx_loss+=(mx-a[i]);
        if(a[i] == mx){
            ++mxs;
        } else{
            ++o;
        }
    }
    int ans = 0;
    //cout << mx_loss << "!\n";
    //cout << o << " " << mxs << "!!\n";
    for(int i=0;i<n;i++){ //how many things we can move after, fixing which thing is in the middle
        if(mx_loss-i <= r){
            //cout << "can have " << i << " things after\n";
            int res = (nCr(o, i) * fact[i])%mod;
            res = (res * fact[n-i-1]);
            ans = (ans+res)%mod;
        }
    }
    ans = (ans * (mxs+1))%mod;
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}