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
    vi d(6);
    d[0] = 1;
    d[1] = 0;
    for(int i=2;i<6;i++){
        d[i] = (i-1)*(d[i-1]+d[i-2]);
    }
    int ans = 0;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<=k;i++){
        int res = 1;
        for(int j=1;j<=i;j++){
            res*=(n-i+j);
            res/=j;
        }
        res*=d[i];
        ans+=res;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
