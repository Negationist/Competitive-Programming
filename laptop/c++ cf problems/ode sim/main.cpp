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
    cout << fixed << setprecision(10);
    auto deriv = [&](ld c){
        ld res = 200*(1-c);
        return res;
    };
    ld y=3,x=0;
    ld ssize = 0.011;
    cout << x << "\n";
    for(int i=1;i<=50;i++){
        ld temp = deriv(y);
        y+=(temp*ssize);
        x+=ssize;
        cout << x << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
