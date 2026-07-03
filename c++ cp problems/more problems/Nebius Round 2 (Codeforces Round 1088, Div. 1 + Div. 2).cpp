#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int mod = 1e9+7;

const int maxN = 1e5;
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
    int n; cin >> n;
    vi b(n+1);
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    vi cnt(28, -1);
    for(int i=1;i<=n;i++){
        int temp = b[i];
        for(int j=0;j<28;j++){
            if(cnt[j] != -1){
                int take = nCr(cnt[j], i);
                take = (take * (1LL<<j));
                take%=mod;
                b[i]+(mod - take);
                b[i]%=mod;
            }
        }
        for(int j=0;j<28;j++){
            if((b[i] & (1LL<<j))){
                cnt[j] = i;
            }
        }
    }
    for(int i=0;i<n;i++){
        int out = 0;
        for(int j=0;j<28;j++){
            if(cnt[j] > 0){
                --cnt[j];
                out+=(1LL<<j);
            }
        }
        cout << out << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    compute();
    while(t--){
        solve();
    }
    return 0;
}