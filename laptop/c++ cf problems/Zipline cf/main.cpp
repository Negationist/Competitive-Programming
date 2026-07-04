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
const ld eps = 1e-8;
void solve(){
    cout << fixed << setprecision(16);
    int w,g,h,r;
    cin >> w >> g >> h >> r;
    ld ans1 = sqrt((abs(g-h)*abs(g-h)+w*w));
    ld lo = 0, hi = w;
    g-=r;
    h-=r;
    while(hi-lo>eps){
        ld m1 = lo+(hi-lo)/3;
        ld m2 = lo+(hi-lo)*2/3;
        ld res1 = sqrt(g*g+m1*m1)+sqrt(h*h+(w-m1)*(w-m1));
        ld res2 = sqrt(g*g+m2*m2)+sqrt(h*h+(w-m2)*(w-m2));
        if(res1<res2){
            hi = m2;
        } else{
            lo = m1;
        }
    }
    cout << ans1 << " " << sqrt(g*g+lo*lo)+sqrt(h*h+(w-lo)*(w-lo)) << "\n";
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
