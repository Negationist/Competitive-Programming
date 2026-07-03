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

int MOD;
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
    mi dp[n][2] = {}; //0 - no ones, 1 - some ones
    mi spots[n]; //spots before the next 1 in total in the sequences with a 1
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int inc = 0;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            if(a[i]==1){
                dp[i][0] = 0;
                dp[i][1] = 1;
            } else if(a[i]==2){
                dp[i][0] = 1;
                dp[i][1] = 1;
            } else{
                dp[i][0] = 0;
                dp[i][1] = 2;
            }
            spots[i] = 0;
        } else{
            if(a[i]==1){
                cout << 0 << "\n";
            } else if(a[i]==2){
                //append 2
                dp[i][0] = dp[i+1][0];
                //append a 1,1
                dp[i][1] = dp[i+1][0]+dp[i+1][1];
                spots[i] = 0;
            } else{
                //append a 2 to the front, append a 1 anywhere before the next one, so we need to know how many spot total there are before the next 1, if no
                dp[i][0] = 0;
                if(dp[i+1][0]!=0){
                    dp[i][1]+=(inc+1); //after appending next 2 we have inc+1 choices
                }
                dp[i][1]+=(spots[i+1]+dp[i+1][1]); //for all sequences we get one more after appending 2
                spots[i] = 
            }
        }
        ++inc;
    }
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