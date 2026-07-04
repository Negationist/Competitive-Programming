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
    int lo,hi,k;
    cin >> lo >> hi >> k;
    int l = lo, r = hi;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(k*lo<=mid){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    if(r<lo){
        cout << 0 << "\n";
    } else{
        int res = r-lo+1;
        res = min(res,hi-lo+1);
        cout << res << "\n";
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
