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
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int l = 0, r = n-1;
    int ans1 = 0, ans2 = 0;
    while((a[l]+a[r])%2!=0){
        --r;
        ans1++;
    }
    r = n-1;
    while((a[l]+a[r])%2!=0){
        ++l;
        ans2++;
    }
    cout << min(ans1,ans2) << "\n";
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
