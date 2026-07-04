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
    int n;
    cin >> n;
    vector<vi> a(2,vi(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int add = -LLONG_MAX;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=max(a[0][i],a[1][i]);
        int low = min(a[0][i],a[1][i]);
        add = max(add,low);
    }
    cout << ans+add << "\n";
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
