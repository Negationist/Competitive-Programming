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
    int l=1,r=n-2;
    while(l<r){
        if(a[l]==a[l-1] || a[r]==a[r+1]){
            swap(a[l],a[r]);
        }
        l++;
        r--;
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        ans+=(a[i]==a[i+1]);
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
