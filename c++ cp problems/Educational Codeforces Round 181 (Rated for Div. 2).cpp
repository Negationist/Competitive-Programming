#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

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
  mi() { v = 0; }
  mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mi &operator-=(mi &a, mi b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,mi>>> buckets(m+1);
    for(int i=0;i<n;i++){
        int l,r,p,q;
        cin >> l >> r >> p >> q;
        buckets[r].pb({l,mi(p)/mi(q)});
    }
    vector<mi> pref(m+1);
    pref[0] = 1;
    vector<mi> dp(m+1,0);
    dp[0] = 1;
    for(int i=1;i<=m;i++){
        pref[i] = pref[i-1];
        for(auto [l,prob] : buckets[i]){
            pref[i]*=(1-prob);
        }
        for(auto [l,prob] : buckets[i]){
            mi res = dp[l-1]*prob*(pref[i]/(pref[l-1]*(mi(1)-prob)));
            dp[i]+=res;
        }
    }
    cout << dp[m].v << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}