#include <bits/stdc++.h>
#define int long long
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

const double eps = 1e-12;

void solve(){
    int r,c; double p, high, low;
    cin >> r >> c >> p;
    vector<vector<double>> dp(r,vector<double>(c));
    auto eval = [&](){
        double x = min(p,high-low);
        double res = 0.5*low + 0.5*(x/p)*(0.5*x+low)+0.5*(1-x/p)*high;
        return res;
    };
    dp[r-1][c-1] = 0.0;
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(i==r-1 && j==c-1) continue;
            if(i==r-1){
                dp[i][j] = 0.25*p+dp[i][j+1];
            } else if(j==c-1){
                dp[i][j] = 0.25*p+dp[i+1][j];
            } else{
                low = dp[i][j+1], high = dp[i+1][j];
                if(low>high) swap(low,high);
                dp[i][j] = eval();
            }
        }
    }
    cout << fixed << setprecision(16) << dp[0][0] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}