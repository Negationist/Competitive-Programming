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
    vector<mi> sum(n,0);
    vector<vector<vector<mi>>> dp(n, vector<vector<mi>>(n+1, vector<mi>(n, mi(0)))); //end position, length, start element
    vector<vi> res(n,vi(n,0));
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        res[a][b] = 1;
    }
    auto check = [&](int start, int s, int r){
        for(int i=0;i<s;i++){
            if(res[start+i][(r+i)%s]){
                return false;
            }
        }
        return true;
    };
    for(int i=0;i<n;i++){
        for(int j=1;j<=i+1;j++){
            for(int k=0;k<j;k++){
                int start = i-j+1;
                if(check(start,j,k)){
                    dp[i][j][k]+=((i-j)>=0?sum[i-j]:1);
                    if(k){
                        dp[i][j][k]-=((i-j)>=0?dp[i-j][k][0]:0);
                    }
                }
                //cout << "dp " << i+1 << ", " << j << ", " << k+1 << " is " << dp[i][j][k].v << "\n";
                sum[i]+=dp[i][j][k];
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << sum[i].v << "!!\n";
    // }
    cout << sum[n-1].v << "\n";
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