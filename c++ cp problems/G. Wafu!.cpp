#include <bits/stdc++.h>
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

ll MOD = 1e9+7;
struct mi {
    int v;
    explicit operator int() const { return v; }

    mi() : v(0) {}
    mi(long long _v) : v(int(_v % MOD)) { if (v < 0) v += MOD; }
};
mi &operator+=(mi &a, mi b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mi &operator-=(mi &a, mi b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi(1LL * a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    mi res = 1;
    while (p) { if (p & 1) res *= a; a *= a; p >>= 1; }
    return res;
}
mi inv(mi a) { assert(a.v); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
mi &operator/=(mi &a, mi b) { return a = a / b; }
inline bool operator==(mi a, mi b) { return a.v == b.v; }
inline bool operator!=(mi a, mi b) { return a.v != b.v; }
inline bool operator<(mi a, mi b)  { return a.v <  b.v; }
inline bool operator>(mi a, mi b)  { return a.v >  b.v; }
inline bool operator<=(mi a, mi b) { return a.v <= b.v; }
inline bool operator>=(mi a, mi b) { return a.v >= b.v; }
inline mi abs(mi a) { return (a.v < 0 ? mi(-a.v) : a); }
inline std::ostream& operator<<(std::ostream& os, const mi& x) { return os << x.v; }

const int maxN = 2e5+1;
vector<mi> f(maxN), pref(maxN);

void solve(){
    ll n,k;
    cin >> n >> k;
    mi ans = 1;
    vl a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    auto op = [&](auto self, int x){
        if(x==2){
            ans*=2;
            k = max(k-2,0LL);
            return;
        }
        if(x<40 && k>=(1LL<<(x-1))){
            k-=(1LL<<(x-1));
            ans*=f[x];
        } else{
            --k;
            ans*=x;
            if(!k) return;
            ll lo = 1, hi = 30;
            while(lo<=hi){
                ll mid = lo+(hi-lo)/2;
                ll res = (1LL<<(mid))-1;
                if(res<=k){
                    lo = mid+1;
                } else{
                    hi = mid-1;
                }
            }
            ans*=pref[hi];
            k-=((1LL<<(hi))-1);
            if(k){
                self(self,hi+1);
            }
        }
    };
    sort(all(a));
    for(int i=0;i<n;i++){
        if(k){
            op(op,a[i]);
        }
        ///cout << ans << "\n";
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    f[1] = pref[1] = 1;
    for(int i=2;i<maxN;i++){
        f[i] = i*pref[i-1];
        pref[i] = pref[i-1]*f[i];
    }
    while(t--){
        solve();
    }
    return 0;
}