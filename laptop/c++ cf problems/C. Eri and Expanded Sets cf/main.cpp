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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    map<int,int> dp;
    int ans = n;
    for(int i=1;i<n;i++){
        map<int,int> ndp;
        int diff = abs(a[i]-a[i-1]);
        ndp[diff] = 1;
        for(auto x : dp){
            int cur = __gcd(diff, x.ff);
            ndp[cur]+=x.ss;
        }
        ans+=ndp[0];
        for(int j=0;j<=29;j++){
            int base = 1LL<<j;
            ans+=ndp[base];
        }
        dp = move(ndp);
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
