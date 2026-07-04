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

void solve(){
    int n; cin >> n;
    vi a(n), b(n), pa(n+1, n), pb(n+1, n), dp(n+1);
    dp[n] = n-1;
    for(auto &x : a){ //neat trick
        cin >> x;
        --x;
    }
    for(auto &x : b){ //neat trick
        cin >> x;
        --x;
    }
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        pa[a[i]] = i;
        pb[b[i]] = i;
        if(a[i] == b[i]){
            if(pa[a[i]+1] == pb[b[i]+1]){
                dp[i] = dp[pa[a[i]+1]];
            } else{
                dp[i] = min(pa[a[i]+1], pb[b[i]+1]) - 1;
            }
        }
        if(pa[0] == pb[0]){
            ans+=(dp[pa[0]] - i + 1);
        } else{
            ans+=(min(pa[0], pb[0]) - i);
        }
    }
    cout << ans << '\n';
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