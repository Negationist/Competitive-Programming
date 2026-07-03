#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    vi a(n);
    int mx = -1, best = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<=mx){
            best = max(best,a[i]%mx+mx%a[i]);
        } else{
            if(mx>=a[i]/2+1){
                best = mx = a[i];
            } else{
                mx = a[i];
                for(int j=0;j<i;j++){
                    best = max(best,a[j]%mx+mx%a[j]);
                }
            }
        }
        cout << best << " ";
    }
    cout << "\n";
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
