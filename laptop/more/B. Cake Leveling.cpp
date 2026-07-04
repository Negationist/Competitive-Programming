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
    int mn = LLONG_MAX;
    int sum = 0;
    for(int i=0;i<n;i++){
        int z; cin >> z;
        sum+=z;
        int lo = 0, hi = 1e9+10;
        while(lo <= hi){
            int m = (lo+hi)/2;
            if((i+1) * m <= sum){
                lo = m+1;
            } else{
                hi = m-1;
            }
        }
        mn = min(hi, mn);
        cout << mn << " ";
    }
    cout << "\n";
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