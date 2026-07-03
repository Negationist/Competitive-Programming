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
    int n;
    cin >> n;
    vi a(n+1),b(n+1),c(n+1);
    a[0] = b[0] = c[0] = 0;
    for(int i=1;i<=n;i++){
        char z;
        cin >> z;
        a[i] = a[i-1]+=(z=='H');
        b[i] = b[i-1]+=(z=='P');
        c[i] = c[i-1]+=(z=='S');
    }
    int ans = max(a[n],max(b[n],c[n]));
    for(int i=1;i<n;i++){
        ans = max(ans,a[i]+b[n]-b[i]);
        ans = max(ans,a[i]+c[n]-c[i]);
        ans = max(ans,b[i]+a[n]-a[i]);
        ans = max(ans,b[i]+c[n]-c[i]);
        ans = max(ans,c[i]+a[n]-a[i]);
        ans = max(ans,c[i]+b[n]-b[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    solve();
    return 0;
}
