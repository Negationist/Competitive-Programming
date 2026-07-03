//cloud storage lol

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int gcd(int a, int b){
    if(b%a==0) return a;
    return gcd(b%a,a);
}

void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    int mod = gcd(a,b);
    int mx = -1,mn = LLONG_MAX;
    int z[n];
    for(int i=0;i<n;i++){
        cin >> z[i];
        z[i]%=mod;
    }
    sort(z,z+n);
    int ans = z[n-1] - z[0];
    for(int i=1;i<n;i++){
        ans = min(ans, z[i-1]+mod - z[i]);
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
