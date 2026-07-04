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

unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
const int mn = 1e5, mx = 1e9;
uniform_int_distribution<int> dist(mn,mx);

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int A = dist(rng), B = 1e9+7;
    int pow[n+1];
    pow[0] = 1;
    for(int i=1;i<=n;i++){
        pow[i] = (pow[i-1]*A)%B;
    }
    pair<bool,int> dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i] = {true,s[i]};
    }
    for(int i=0;i+1<n;i++){
        int h = (A*s[i])+s[i+1];
        h%=B;
        dp[i][i+1] = {(s[i]==s[i+1]),h};
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i+k-1<n;i++){
            int j = i+k-1;
            dp[i][j].ff = (dp[i+1][j-1].ff && (s[i]==s[j]));
            int h = (pow[k-1]*s[i])%B;
            h = (h+dp[i+1][j-1].ss)%B;
            h = (h+s[j])%B;
            dp[i][j].ss = h;
        }
    }
    int ans = 0;
    for(int k=1;k<=n;k++){
        set<int> cur;
        for(int i=0;i+k-1<n;i++){
            int j = i+k-1;
            if(dp[i][j].ff){
                cur.insert(dp[i][j].ss);
            }
        }
        ans+=cur.size();
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
