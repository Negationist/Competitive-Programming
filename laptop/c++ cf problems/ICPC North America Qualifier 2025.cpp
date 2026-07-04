#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

int inf = 1e8;

void solve(){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    vector<vi> dp(n,vi(n,inf));
    for(int i=0;i<n;i++) dp[i][i] = 0;
    vector<pair<pii,int>> roads;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        --x; --y;
        dp[x][y] = min(dp[x][y], w);
        roads.pb({{x,y},w});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dp[j][k] = min(dp[j][k], dp[j][i]+dp[i][k]);
            }
        }
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