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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vi b = a;
    sort(b.begin(),b.end());
    if(a == b){
        cout << -1 << "\n";
    } else{
        int mn = b[0], mx = b.back(), ans = mx - mn;
        for(int i=0;i<n;i++){
            if(a[i] == b[i]) continue;
            int cand1 = mx - a[i], cand2 = a[i] - mn;
            ans = min(ans, max(cand1, cand2));
        }
        cout << ans << "\n";
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