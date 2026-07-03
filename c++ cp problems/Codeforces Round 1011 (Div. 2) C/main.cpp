#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int x,y;
    cin >> x >> y;
    if(x==y){
        cout << -1 << "\n";
    } else{
        int z = max(x,y);
        int log = 63-__builtin_clzll(z);
        ++log;
        int ans = (1LL<<log)-z;
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
