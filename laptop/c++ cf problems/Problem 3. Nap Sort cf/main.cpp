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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans = min((n)*(n+1)/2,a.back());
    for(int i=n-1;i>0;i--){
        int num =  n-1-i+1;
        int need = a[i-1];
        int l = 0, r = i;
        int mxtime = (i)*(i+1)/2+i*num;
        if(mxtime<need){
            continue;
        }
        while(l<=r){
            int mid = l+(r-l)/2;
            int res = ((mid)*(mid+1)/2)+mid*num;
            if(res>=need){
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        num+=l;
        //cout << "num for " << i+1 << " is " << num << "\n";
        int ftime = num*(num+1)/2;
        ans = min(ans, ftime);
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
