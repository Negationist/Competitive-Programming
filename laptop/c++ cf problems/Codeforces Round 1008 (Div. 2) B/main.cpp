#include <bits/stdc++.h>
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
    int n,k;
    cin >> n >> k;
    if(k&1){
        for(int i=0;i<n-1;i++){
            cout << n << " ";
        }
        cout << n-1 << "\n";
    } else{
        for(int i=0;i<n-2;i++){
            cout << n-1 << " ";
        }
        cout << n << " " << n-1 << "\n";
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
