#include <bits/stdc++.h>
#define int long long
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
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n,d; cin >> n >> d;
    vi a(1,0);
    for(int i=0;i<n;i++){
        int z; cin >> z;
        a.pb(z);
    }
    for(int i=1;i<=n;i++){
        a.pb(a[i]);
    }
    for(int i=1;i<=n;i++){
        a.pb(a[i]);
    }
    vi pref(4*n+5,0);
    for(int i=1;i<(int)(a.size());i++){
        pref[i] = pref[i-1]+a[i];
    }
    int ans = 0;
    for(int i=n+1;i<n+1+n;i++){
        int self = a[i] * 2 * d;
        int res = pref[i-1] - pref[i-1-d] + pref[i+d] - pref[i];
        ans+=max(0LL, self - res);
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
