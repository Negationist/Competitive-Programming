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
const ld e = 2.718281828459045235360287471352;
const ld eps = 1e-9;
void solve(){
    cout << fixed << setprecision(10);
    ld t = 0, y = 1;
    cout << t << " " << y << "\n";
    ld delta = 0.1;
    for(int i=0;i<55;i++){
        ld rate = 2-pow(e,-4*t)-2*y;
        t+=delta;
        y+=(rate*delta);
        if(abs(round(t)-t)>eps) continue;
        cout << t << " " << y << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
