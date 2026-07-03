#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const ld eps = 1e-12;
void solve(){
    int n,l,q;
    cin >> n >> l >> q;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    auto check = [&](int z, int p, int w){
        ld x = l-(ld)l*p/w;
        ld u = (ld)l/a[z];
        int lo = 0, hi = z;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            ld distance = (a[z]-a[mid])*u;
            if(x-distance > eps){
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        return z-lo+1;
    };
    while(q--){
        int p,w; cin >> p >> w;
        cout << check(n-1,p,w) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
