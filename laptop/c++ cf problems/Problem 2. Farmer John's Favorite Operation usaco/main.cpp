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
    int n,m;
    cin >> n >> m;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]%=m;
    }
    sort(a.begin(),a.end());
    int pref[n];
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1]+a[i];
    }
    int ans = LLONG_MAX;
    for(int i=0;i<n;i++){
        int x = a[i];
        int mx = m/2;
        int l = 0, r=i;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(x-a[mid]<=mx){
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        int lo = l;
        l = i, r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(a[mid]-x<=mx){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        int hi = r;
        int res1 = (pref[hi]-(i?pref[i-1]:0))-x*(hi-i+1);
        int res2 = x*(i-lo+1)-(pref[i]-(lo?pref[lo-1]:0));
        int res3 = m*(n-1-hi)-((pref[n-1]-pref[hi])-x*(n-1-hi));
        int res4 = 0;
        if(lo){
            res4 = m*lo-(x*(lo)-pref[lo-1]);
        }
        int temp = res1+res2+res3+res4;
        ans = min(temp,ans);
        //cout << "for " << a[i] << ": res1 is " << res1 << ". res2 is " << res2 << ". res3 is " << res3;
        //cout << ". res4 is " << res4 << "\n";
        //cout << "hi is " << hi << ". lo is " << lo << "\n";
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
