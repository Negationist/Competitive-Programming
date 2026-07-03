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

void solve(){
    int n;
    cin >> n;
    vi a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    mi dp[n+1][n+1] = {}; //i, mx, mx that has greater
    mi sum1[n+1][n+1] = {}; //sum of all with mx = j, mx greater<=k, 
    mi sum2[n+1][n+1] = {}; //sum of all with mx <= j, mx greater=k, 
    for(int i=0;i<=n;i++){
        sum1[0][i] = 1;
    }
    for(int i=0;i<=n;i++){
        sum2[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        vector<vector<mi>> n_dp(n+1,vector<mi>(n+1,0));
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(j==0 && k==0){
                    dp[i][0][0] = 1;
                } else{
                    if(j<=k){
                        dp[i][j][k] = 0;
                    } else{
                        dp[i][j][k] = dp[i-1][j][k];
                        if(a[i]>j){
                            //do nothing
                        } else if(a[i]==j){
                            dp[i][j][k]+=sum2[i-1][a[i]][k];
                            //add all dps with mx greater of k and mx<=a[i]
                        } else if(a[i]==k){
                            dp[i][j][k]+=sum1[i-1][j][a[i]];
                            //add all dps with a mx greater <= k, and mx = j
                        }
                    }
                }
                sum1[i][j][k] = dp[i][j][k]+(k?sum1[i][j][k-1]:0);
                sum2[i][j][k] = dp[i][j][k]+(j?sum2[i][j-1][k]:0);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                //cout << "dp " << i << " " << j << " " << k << "is " << dp[i][j][k] << "\n";  
            }
        }
    }
    mi ans = 0;
    for(int j=0;j<=n;j++){
        for(int k=0;k<=n;k++){
            ans+=dp[n][j][k];
        }
    }
    cout << ans << "\n";
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