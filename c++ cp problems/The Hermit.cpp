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

int MOD = 998244353;
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

const int maxN = 1e5+1;

vector<vi> adj(maxN,vi());
vector<mi> fact(maxN);

void compute(){
    for(int i=1;i<maxN;i++){
        for(int j=2*i;j<maxN;j+=i){
            adj[j].pb(i);
        }
    }
    fact[0] = 1;
    for(int i=1;i<maxN;i++){
        fact[i] = i*fact[i-1];
    }
}

mi nCr(int n, int r){
    if(n<0 || r<0) return 0;
    if(n<r) return 0;
    return fact[n]/(fact[n-r]*fact[r]);
}

void solve(){
    int m,n;
    cin >> m >> n;
    vector<vector<mi>> dp(maxN,vector<mi>(20,0));
    for(int i=1;i<maxN;i++){
        dp[i][1] = 1;
    }
    for(int i=1;i<=maxN;i++){
        for(int j=2;j<=19;j++){
            for(int x : adj[i]){
                dp[i][j]+=dp[x][j-1];
            }
        }
    }
    mi ans = 0;
    //case 1, at least one thing is deleted
    for(int i=1;i<=m;i++){
        for(int j=1;j<=19;j++){
            for(int k=i*2;k<=m;k+=i){
                int choices_i = ((m-m%i)/i)-k/i, choices_k = ((m-m%k)/k)-1;
                mi res = dp[i][j] * (nCr(choices_i,n-j-1) - nCr(choices_k,n-j-1)) * (n-j-1>0);
                if(res != 0){
                    cout << "on dp " << i << " " << j << " with k being " << k << " adding " << res << "\n";
                }
                ans+=res;
            }
        }
    }
    //case 2, no deletes
    for(int i=1;i<=m;i++){
        int choices_i = ((m-m%i)/i)-1;
        int num = m-i-choices_i; //choose something not divisible
        mi res = num*nCr(m-i-1, n-2)*(n);
        ans+=res;
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