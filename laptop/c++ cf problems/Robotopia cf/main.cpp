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
const int eps = 1e-12;
void solve(){
    int l1,a1,l2,a2,i,j;
    cin >> l1 >> a1 >> l2 >> a2 >> i >> j;
    int cnt = 0;
    pii ans;
    for(int x=1;x<=10000;x++){
        int y = (i+j-x*l1-x*a1)/(l2+a2);
        ld yr = (i+j-x*l1-x*a1)/(l2+a2);
        if(abs(y-yr)>eps) continue;
        pii cur = {x,y};
        if(y<=10000 && y>=1){
            int _i = x*l1+y*l2;
            int _j = x*a1+y*a2;
            if(_i==i && _j==j){
                ++cnt;
                ans = cur;
            }
        }
    }
    if(cnt==1){
        cout << ans.ff << " " << ans.ss << "\n";
    } else{
        cout << "?\n";
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
