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

void solve(){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int _xor = 0;
    int big = 0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        _xor^=z;
        big^=z;
        if(_xor<=k){
            ans++;
            _xor = 0;
        }
    }
    if(big<=k){
        cout << ans << "\n";
    } else{
        cout << -1 << "\n";
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
