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
    int x,y; cin >> x >> y;
    int p = 0, q = 0;
    for(int i=0;i<30;i++){
        if(x&(1LL<<i)){
            p|=(1LL<<i);
        } else if(y&(1LL<<i)){
            q|=(1LL<<i);
        }
    }
    cout << p << " " << q << "\n";
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