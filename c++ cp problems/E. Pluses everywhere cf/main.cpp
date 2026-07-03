#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int maxN = 1e5+5;
const int mod = 1e9+7;
vi fact(maxN);

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i)%mod;
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

int modInv(int x, int mod){
    return binPowMod(x,mod-2,mod);
}

int nCr(int n, int r){
    int res = fact[n]*modInv(fact[n-r],mod);
    res%=mod;
    res = res*modInv(fact[r],mod);
    res%=mod;
    return res;
}

void solve(){
    int n,k,ans=0;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '+'+s;
    vi pow2(n+10),pow10(n+10);
    pow2[0] = pow10[0] = 1;
    for(int i=1;i<n+10;i++){
        pow2[i] = (pow2[i-1]*2)%mod;
        pow10[i] = (pow10[i-1]*10)%mod;
    }
    vi pref1(n+1,0), pref10(n+1,0);
    for(int i=1;i<=n;i++){ //one based, dont forget
        int cur = s[i]-'0';
        pref1[i] = pref1[i-1]+cur;
        pref10[i] = ((pref10[i-1]*10)+cur)%mod;
    }
    if(k==0){
        cout << pref10[n] << "\n";
        return;
    }
    int sum = 0; //this is the sum of all expressions of length 0, but will be updated
    for(int l=1;l<=n;l++){
        int ways;
        int slots = n-l-2;
        int left = k-2;
        if(slots<left || left<0){
            break;
        } else{
            ways = nCr(slots,left);
        }
        sum = (sum+pref1[n-l+1]*pow10[l-1])%mod;
        //int extra = pref10[l-1];
        //sum = (sum-extra+mod)%mod;
        //cout << "addend is " << pref1[n-l+1]*pow10[l-1] << "\n";
        //cout << "extra is " << extra << '\n';
        //cout << "ways is " << ways << '\n';
        //exclude prefixes and suffixes
        int prefix = pref10[l];
        int suffix = (pref10[n]-pref10[n-l]*pow10[l])%mod;
        //cout << "prefix is " << prefix << ". suffix is " << suffix << "\n";
        sum = (sum-prefix-suffix+2*mod)%mod;
        //cout << "sum is " << sum << "\n";
        int res = (sum*ways)%mod;
        //cout << "res is " << res << "\n";
        ans = (ans+res)%mod;
        sum+=suffix;
        //cout << "adding back " << suffix << "\n";
    }
    for(int l=1;l<=n;l++){
        int prefix = pref10[l];
        int suffix = (pref10[n]-pref10[n-l]*pow10[l]+100*mod)%mod;
        int slots = n-l-1;
        int left = k-1;
        if(slots>=left){
            int res = ((prefix+suffix)*nCr(slots,left))%mod;
            ans = (ans+res)%mod;
        } else{
            break;
        }
    }
    if(ans<0){
        ans = (ans+100*mod)%mod;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
