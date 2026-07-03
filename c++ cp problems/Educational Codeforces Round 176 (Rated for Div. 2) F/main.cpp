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
    int n,k;
    cin >> n >> k;
    if(n<=k){
        cout << 1 << "\n";
        return;
    }
    int ans = 0;
    if(n&1){
        ++ans;
        n-=k;
    }
    int k_even = k-1;
    ans+=(n+k_even-1/k_even);
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
