#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int msb = 63-__builtin_clzll(m);
    if (n & (1LL << msb)) {
        cout << "1\n" << n << " " << m << "\n";
        return;
    }
    int top = 63-__builtin_clzll(n);
    n-=(1LL<<top);
    if ((63-__builtin_clzll(n)) > msb) {
        cout << "2\n";
        n+=(1LL<<top);
        int res = (1LL << msb) + (1LL << top);
        cout << n << " " << res << " " << m << "\n";
    } else {
        cout << -1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
