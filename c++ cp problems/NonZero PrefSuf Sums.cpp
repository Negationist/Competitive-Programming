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

int MOD;
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
    cin >> n >> m >> MOD;
    vector<vector<mi>> dp(n*m*2+10, vector<mi>(m+1,1));
    vector<vector<mi>> sum(n*m*2+10, vector<mi>(m+1,0)); //dont let k = 0
    auto idx = [&](int x){
        return n*m+5+x;
    };
    for(int j=-n*m;j<=n*m;j++){
        for(int k=0;k<=m;k++){
            if(j<0){
              if(-k!=j){
                   dp[idx(j)][k] = 0;
              }
            } else if(j==0){
                if(k){
                   dp[idx(j)][k] = 0;
                }
            } else if(j==1){
                if(k){
                   dp[idx(j)][k] = 0;
                }
            } else{
                dp[idx(j)][k] = 0;
            }
            sum[idx(j)][k] = sum[idx(j)-1][k]+(k?sum[idx(j)][k-1]:0)-(k?sum[idx(j)-1][k-1]:0)+dp[idx(j)][k];
        }
    }
    for(int i=0;i<n-1;i++){
        vector<vector<mi>> ndp(n*m*2+10, vector<mi>(m+1,0));
        vector<vector<mi>> nsum(n*m*2+10, vector<mi>(m+1,0)); //dont let k = 0
        for(int j=-n*m;j<=n*m;j++){
            for(int k=0;k<=m;k++){
                ndp[idx(j)][k]+=dp[idx(j)][k]; //its 0 
                ndp[idx(j)][k]+=dp[idx(j)-1][k]; //its 1
                if(k){ 
                    ndp[idx(j)][k]+=(sum[idx(j+k)][k]-sum[idx(j+k-1)][k]); //its k and k!=0
                    int mx_sum = j+k-1, mn_sum = j+1;
                    if(k>1){
                      mi res = (sum[idx(mx_sum)][k] - sum[idx(mn_sum)][k]) - (sum[idx(mx_sum)][k-1] - sum[idx(mn_sum)][k-1]);
                      ndp[idx(j)][k]+=res; //its negative and >k
                    }
                } 
                cout << "dp " << j << " " << k << " is " << ndp[idx(j)][k].v << "\n";
                nsum[idx(j)][k] = nsum[idx(j)-1][k]+(k?nsum[idx(j)][k-1]:0)-(k?nsum[idx(j)-1][k-1]:0)+ndp[idx(j)][k];
            }
        }
      dp = move(ndp);
      sum = move(nsum);
    }
    mi cnt = 0;
    for(int j=-n*m;j<=n*m;j++){
        for(int k=0;k<=m;k++){
            if(j>0){
                if(k>j-2){
                  int factor;
                  if(k>1){
                      factor = m/k;
                  } else{
                      factor = m;
                  }
                  cnt+=(factor*dp[idx(j)][k]);
                }
            }
        }
    }
    cout << cnt.v << "!\n";
    mi zdp[n+1][n*m*2+10] = {};
    zdp[0][idx(0)] = 1;
    for(int i=1;i<=n;i++){
        for(int j=-n*m;j<=n*m;j++){
            for(int k=-m;k<=m;k++){
              int old = j-k;
              if(old>=-n*m && old<=n*m){
                  zdp[i][idx(j)]+=zdp[i-1][idx(old)];
              }
            }
        }
    }
    cnt+=zdp[n][idx(0)];
    cout << cnt.v << "!\n";
    mi all = 1;
    for(int i=0;i<n;i++){
        all*=(mi(2*m+1));
    }
    all-=cnt;
    cout << all.v << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}