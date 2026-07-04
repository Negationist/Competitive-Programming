#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
const int mod = 998244353;
const int maxN = 3*1e5+5;
int pow2[maxN];

void compute(){
    pow2[0] = 1;
    for(int i=1;i<maxN;i++){
        pow2[i] = (pow2[i-1]*2)%mod;
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> b1(n);
    for(int i=0;i<n;i++) cin >> b1[i];
    vector<string> b2(m,string(n,' '));
    int num = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b2[j][i] = b1[i][j];
            num+=(b2[j][i]=='o');
        }
    }
    auto horz = [&](vector<string> &b)->int{
        int result = 0;
        n = b.size();
        m = b[0].size();
        for(int i=0;i<n;i++){
            vector<vi> dp(m,vi(2));
            int loss = 0;
            for(int j=0;j<m;j++){
                if(!j){
                    dp[j][0] = 1;
                    dp[j][1] = 0;
                } else{
                    dp[j][0] = pow2[loss];
                    int good = ((b[i][j]=='o')&&(b[i][j-1]=='o'));
                    if(j==1){
                        dp[j][1] = good;
                    } else{
                        dp[j][1] = good*(dp[j-2][1]+dp[j-2][0]);
                        dp[j][1]%=mod;
                    }
                }
                loss+=(b[i][j]=='o');
                int res = (dp[j][1]*pow2[num-loss])%mod;
                res%=mod;
                result = (result+res)%mod;
                //cout << "dp " << j << " " << 0 << " is " << dp[j][0] << "\n";
                //cout << "dp " << j << " " << 1 << " is " << dp[j][1] << "\n";
            }
        }
        return result;
    };
    int ans = (horz(b1)+horz(b2))%mod;
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
