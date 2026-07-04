#include <bits/stdc++.h>
#define int long long
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
    n = n-1;
    k = k-1;
    if(k>n-k) k = n-k;
    int res = 1;
    for(int i=0;i<k;i++){
        res = res * (n-i) / (i+1);
    }
    cout << res << "\n";
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
