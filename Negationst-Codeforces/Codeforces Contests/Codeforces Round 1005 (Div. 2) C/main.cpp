#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi pref(n),suff(n);
    pref[0] = (a[0]>0?a[0]:0);
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1]+(a[i]>0?a[i]:0);
    }
    suff[n-1] = (a[n-1]<0?-a[n-1]:0);
    for(int i=n-2;i>=0;i--){
        suff[i] = suff[i+1]+(a[i]<0?-a[i]:0);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int res = pref[i]+(i!=n-1?suff[i+1]:0);
        ans = max(ans,res);
    }
    ans = max(ans,suff[0]);
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
