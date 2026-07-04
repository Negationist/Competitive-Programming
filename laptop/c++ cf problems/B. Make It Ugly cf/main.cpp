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
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int r=n-1;
    while(true){
        if(r<0) {
            cout << -1 << endl;
            return;
        }
        if(a[r]!=a[n-1]) break;
        r--;
    }
    int ans = n-1-r;
    int index=-1;
    for(int i=0;i<n;i++){
        if(i==r+1) break;
        if(a[i]!=a[0]){
            ans = min(ans,i-index-1);
            index = i;
        }
    }
    cout << ans << endl;
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
