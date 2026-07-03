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

void solve(){
    int n,k;
    cin >> n >> k;
    if(!k){
        cout << 0 << "\n";
        return;
    }
    if(k >= 28){
        cout << __builtin_popcount(n) + k - 1 << "\n";
    } else{
        vi a;
        bool in = false;
        int cnt = 0;
        for(int i=0;i<30;i++){
            if(in){
                if(n & (1LL<<i)){
                    ++cnt;
                } else{
                    a.pb(cnt);
                    in = false;
                    cnt = 1;
                }
            } else{
                if(n & (1LL<<i)){
                    a.pb(-cnt);
                    in = true;
                    cnt = 1;
                } else{
                    ++cnt;
                }
            }
            if(i == 29){
                a.pb(cnt * (in? 1 : -1));
            }
        }
        vii temp;
        for(int i=0;i<sz(a);i++){
            if(a[i] > 0){
                if(i != sz(a)-1){
                    temp.pb({a[i], -a[i+1]-1}); //num, ops to bring it
                } else{
                    temp.pb({a[i], 0});
                }
            }
        }
        int dp[sz(temp)][k+1][2];
        for(int i=0;i<sz(temp);i++){
            for(int j=0;j<=k;j++){
                dp[i][j][0] = 100;
                dp[i][j][1] = 100;
            }
        }
        dp[0][0][0] = temp[0].ff;
        dp[0][1][1] = 1;
        for(int i=1;i<sz(temp);i++){
            for(int j=0;j<=k;j++){
                dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]) + temp[i].ff;
                if((j - temp[i-1].ss - 1) >= 0){
                    dp[i][j][1] = dp[i-1][j - temp[i-1].ss - 1][1];
                }
                if(j>0){
                    int mn = min(dp[i-1][j-1][0], dp[i-1][j-1][1]);
                    dp[i][j][1] = min(dp[i][j][1], mn + 1);
                }
            }
        }
        int ans = 100;
        for(int i=sz(temp)-1;i<sz(temp);i++){
            for(int j=0;j<=k;j++){
                ans = min(ans, dp[i][j][0]);
                ans = min(ans, dp[i][j][1]);
            }
        }
        cout << __builtin_popcount(n) + k - ans << "\n";
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