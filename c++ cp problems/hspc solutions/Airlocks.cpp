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

const int maxN = 4e5;
mi fact[maxN], factInv[maxN];

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i);
    }
    factInv[maxN-1] = mi(1) / fact[maxN-1];
    for(int i=maxN-2;i>=0;i--){
        factInv[i] = (factInv[i+1]*(i+1));
    }
}

mi nCr(int n, int r){
    if(n==-1 && r==-1) return mi(1);
    if(n<r) return mi(0);
    mi res = fact[n]*factInv[n-r];
    res = res*factInv[r];
    return res;
}

void solve(){
    int n; cin >> n;
    vi cnt(n);
    mi ans = 0;
    for(int i=0;i<n;i++){
        cin >> cnt[i];
        ans+=cnt[i];
    }
    n = sz(cnt);
    vi p(n);
    bool flag = false;
    for(int i=n-1;i>=0;i--){
        if(i == n-1){
            p[i] = cnt[i];
        } else if(i==0){
            if(p[1] != cnt[0]){
                flag = true;
            }
        } else{
            p[i] = cnt[i] - p[i+1];
            if(p[i] < 0){
                flag = true;
            }
        }
    }
    if(flag){
        cout << "0\n";
        return;
    }
    if(n==1){
        if(cnt[0] <= 1){
            cout << "1\n";
        } else{
            cout << "0\n";
        }
        return;
    }
    for(int i=2;i<n;i++){
        ans*=nCr(p[i] + p[i-1] - 1 , p[i-1] - 1);
    }
    ans /= cnt[0];
    cout << ans.v << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
