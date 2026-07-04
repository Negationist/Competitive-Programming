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
const ld eps = 1e-7;
void solve(){
    ld a,b,c,d;
    cin >> a >> b >> c >> d;
    ld x = (a-1)/c;
    ld y = (b-1)/d;
    if(abs(x-y)<eps){
        cout << "SAME\n";
    } else if(x<y){
        cout << "TAOYUAN\n";
    } else{
        cout << "JAKARTA\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
