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
const int mod = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<int,int> cnt;
    cnt[0] = 1;
    int g = 0;
    for(int i=0;i<n;i++){
        int g_new = g^a[i];
        cnt[g] = (cnt[g]*3)%mod;
        cnt[a[i]^g_new]+=cnt[g_new]*2;
        cnt[a[i]^g_new]%=mod;
        g = g_new;
    }
    int ans = 0;
    for(auto x : cnt){
        ans = (ans+x.ss)%mod;
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
