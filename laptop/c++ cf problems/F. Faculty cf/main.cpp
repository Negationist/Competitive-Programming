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
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    for(int i=10000;i<=10000;i++){
        int best = -1;
        vi nums;
        for(int j=2;j<=i;j++){
            int res = i%j+j%i;
            int res2 = i%(j-1)+(j-1)%i;
            if(res>=res2){
                cout << "beauty with " << j << " is " << res << "\n";
            }
            /*if(res>best){
                best = res;
                nums.clear();
                nums.pb(j);
            } else if(res==best){
                nums.pb(j);
            }*/
        }
        /*cout << "For " << i << " the best beauty was " << best << " with ";
        for(int x : nums){
            cout << x << " ";
        }*/
        cout << "\n";
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
