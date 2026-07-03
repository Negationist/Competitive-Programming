#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
//
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi diff(n-1);
    int mx = -LLONG_MIN;
    map<int,int> seen;
    for(int i=0;i<n;i++){
        cin >> a[i];
        seen[a[i]] = 1;
        if(i){
            diff[i-1] = abs(a[i]-a[i-1]);
        }
        mx = max(a[i],mx);
    }
    if(n==1){
        cout << 1 << "\n";
        return;
    }
    int x = diff[0];
    for(int y : diff){
        x = __gcd(x,y);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int res = (mx-a[i])/x;
        ans+=res;
    }
    int lo = mx;
    int xtra = 0;
    while(seen[lo]){
        lo-=x;
        ++xtra;
    }
    xtra = min(xtra,n);
    cout << ans+xtra << "\n";
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
