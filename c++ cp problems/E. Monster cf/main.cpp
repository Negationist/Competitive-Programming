#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    int mx = sqrtl(2LL*z);
    int ans = LLONG_MAX;
    for(int i=1;i<=mx;i++){ //case on a
        int l = 1, r=z;
        while(l<=r){
            int mid = l+(r-l)/2;
            int c = min(i/k,mid);
            int res = k*c*(c+1)/2+i*(mid-c);
            if(res>=z){
                int cost = i*x+mid*y;
                ans = min(ans,cost);
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
    }
    for(int i=1;i<=mx;i++){ //case on b
        int l = 1, r=z;
        while(l<=r){
            int mid = l+(r-l)/2;
            int c = min(mid/k,i);
            int res = k*c*(c+1)/2+mid*(i-c);
            if(res>=z){
                int cost = mid*x+i*y;
                ans = min(ans,cost);
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
    }
    cout << ans << "\n";
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
