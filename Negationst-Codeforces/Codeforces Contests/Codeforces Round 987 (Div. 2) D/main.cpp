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
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi mn(n),mx(n);
    mx[0] = a[0];
    mn[n-1] = a[n-1];
    for(int i=1;i<n;i++){
        mx[i] = max(a[i],mx[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        mn[i] = min(a[i],mn[i+1]);
    }
    vi ans(n);
    ans[n-1] = mx[n-1];
    for(int i=n-2;i>=0;i--){
        if(mx[i]>mn[i+1]){
            ans[i] = ans[i+1];
        } else{
            ans[i] = mx[i];
        }
    }
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
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
