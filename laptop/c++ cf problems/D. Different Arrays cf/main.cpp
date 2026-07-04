#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
const int maxN = 100000;
const int mod = 998244353;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    int sze = 2*maxN+5;
    vector<vi> dp(n, vi(sze,0));
    for(int i=0;i<n;i++) cin >> a[i];
    dp[2][a[2]-a[1]+maxN] = 1;
    dp[2][a[2]+a[1]+maxN] = 1;
    for(int i=3;i<n;i++){
        for(int j=-maxN;j<maxN;j++){
            int goal1 = j-a[i];
            int goal2 = a[i]-j;
            if(goal1+maxN>=0 && goal1+maxN<sze){
                dp[i][j+maxN]+= dp[i-1][goal1+maxN];
            }
            if(goal1!=goal2 && goal2+maxN>=0 && goal2+maxN<sze){
                dp[i][j+maxN]+= dp[i-1][goal2+maxN];
            }
            dp[i][j+maxN]%=mod;
        }
    }
    int ans = 0;
    for(int i=0;i<sze;i++){
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout << ans << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
