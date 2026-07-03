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
using u128 = unsigned __int128;
using i128 = __int128;
void solve(){
    int n;
    cin >> n;
    if(n==1){
        cout << 2 << "\n";
        return;
    }
    vi dp(n+1,0), pref(n+1);
    int sum = 2;
    dp[1] = 1;
    auto make = [&]()->void{
        pref[0] = 0;
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1]+dp[i];
        }
    };
    make();
    for(int i=2;i<=n;i++){
        vi ndp(n+1);
        for(int j=0;j<=i;j++){

        }
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
