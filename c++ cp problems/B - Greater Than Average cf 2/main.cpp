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
    int n,ans = 0;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int j = 0, sum = a[0];
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]) continue;
        int mx = a[i+1];
        while(j+1<n && ((sum+a[j+1])/(j+2))<mx){
            ++j;
            sum+=a[j];
        }
        ans = max(ans,j-i);
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
