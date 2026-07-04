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
    int n;
    cin >> n;
    n*=2;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int f = a.back();
    int l = 0, r = n-2;
    int cur = 1;
    int sum = 0;
    vi out;
    while(l<=r){
        if(!cur){
            sum+=a[l];
            out.pb(a[l]);
            l++;
        } else{
            sum-=a[r];
            out.pb(a[r]);
            r--;
        }
        cur = 1-cur;
    }
    cout << f << " " << f-sum << " ";
    for(int x : out){
        cout << x << " ";
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
