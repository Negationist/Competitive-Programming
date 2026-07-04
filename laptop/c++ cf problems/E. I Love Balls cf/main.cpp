#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
const int mod = 1e9+7;

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

void debug(pii a){
    cout << a.ff << " " << a.ss << "!\n";
}

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    auto sum = [&](const pii &a, const pii &b)->pii{
        pii res = {a.ff*b.ss+a.ss*b.ff, a.ss*b.ss};
        res.ff%=mod;
        res.ss%=mod;
        return res;
    };
    auto diff = [&](const pii &a, const pii &b)->pii{
        pii res = {a.ff*b.ss-a.ss*b.ff, a.ss*b.ss};
        res.ff%=mod;
        res.ss%=mod;
        return res;
    };
    auto prod = [&](const pii &a, const pii &b)->pii{
        pii res = {a.ff*b.ff, a.ss*b.ss};
        res.ff%=mod;
        res.ss%=mod;
        return res;
    };
    auto normalize = [&](const pii &a)->pii{
        if(a.ff==0){
            return {0,1};
        }
        int z = __gcd(a.ff,a.ss);
        pii res = {a.ff/z,a.ss/z};
        return res;
    };
    auto inverse = [&](const pii &a){
        int res = (a.ff*modInv(a.ss,mod))%mod;
        return res;
    };
    vii dps(n+1);
    vii dpa(n+1);
    dps[0] = {0,1};
    dps[1] = {k,n};
    dpa[0] = {0,1};
    dpa[1] = {1,1};
    pii special = {k,n};
    pii non = {n-k,n};
    for(int i=2;i<=n;i++){
        pii res1 = prod(special, sum({1,1},dps[i-1]));
        pii sballsall = prod(special,{i,1});
        pii res2 = prod(non,diff(sballsall,dps[i-1]));
        dps[i] = sum(res1,res2);
        pii res3 = prod(special, sum({1,1},dpa[i-1]));
        pii res4 = prod(non,diff({i+1,1},dpa[i-1]));
        dpa[i] = sum(res3,res4);
    }
    dps[n] = normalize(dps[n]);
    dpa[n] = normalize(dpa[n]);
    for(int i=0;i<=n;i++){
        debug(dps[i]);
    }
    int sums = 0, sumn = 0;
    for(int i=0;i<k;i++){
        sums+=a[i];
    }
    for(int i=k;i<n;i++){
        sumn+=a[i];
    }
    pii avgs = {sums,max(k,1LL)};
    pii avgn = {sumn,max(n-k,1LL)};
    pii sballs = dps[n];
    pii nballs = diff(dpa[n],dps[n]);
    pii ev1 = sum(prod(avgs,sballs),prod(avgn,nballs));
    sballs = diff({k,1},sballs);
    nballs = diff({n-k,1},nballs);
    pii ev2 = sum(prod(avgs,sballs),prod(avgn,nballs));
    ev1 = normalize(ev1);
    ev2 = normalize(ev2);
    cout << inverse(ev1) << " " << inverse(ev2) << "\n";
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
