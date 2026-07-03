#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
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

int MOD = 1e9+7;
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

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    vector<mi> pref(k+1,1);
    for(int i=0;i<n;i++){
        int z; cin >> z;
        vector<mi> n_pref(k+1);
        n_pref[0] = 1;
        for(int j=1;j<=k;j++){
            mi res = pref[j] - (j-z-1>=0?pref[j-z-1]:0);
            n_pref[j] = n_pref[j-1]+res;
        }
        pref = move(n_pref);
    }
    cout << pref[k]-pref[k-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}