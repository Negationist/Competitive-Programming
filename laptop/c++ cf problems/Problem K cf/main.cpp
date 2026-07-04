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
const ld eps = 10e-7;
void solve(){
    cout << fixed << setprecision(16);
    ld w,g,h,r;
    cin >> w >> g >> h >> r;
    ld mn = sqrt(w*w+abs(g-h)*abs(g-h));
    ld lo = 0, hi=w;
    //ld res1 = sqrt(w*w+(g-r)*(g-r))+sqrt((h-r)*(h-r));
    //ld res2 = sqrt((g-r)*(g-r))+sqrt(w*w+(h-r)*(h-r));
    w*=0.5;
    ld res = sqrt(w*w+(g-r)*(g-r))+sqrt(w*w+(h-r)*(h-r));
    cout << mn << " " << res << "\n";
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
