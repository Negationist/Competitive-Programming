
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
    int n,x;
    cin >> n >> x;
    int a[n];
    int mx = -1;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        sum+=a[i];
    }
    int ans = (sum+x-1)/x;
    cout << max(mx,ans) << "\n";
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
