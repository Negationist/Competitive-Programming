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
    cout << fixed << setprecision(16);
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ld ans = 0;
    ld sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        ans = max(ans,sum/(i+1));
    }
    sum = 0;
    for(int i=n-1;i>=0;i--){
        sum+=a[i];
        ans = max(ans,sum/(n-i));
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
