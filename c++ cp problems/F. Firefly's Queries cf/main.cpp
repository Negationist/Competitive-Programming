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
    int n,q;
    cin >> n >> q;
    vi a(1);
    a[0] = 0;
    int act[n];
    for(int i=0;i<n;i++){
        cin >> act[i];
        a.pb(a.back()+act[i]);
    }
    for(int i=0;i<n;i++){
        a.pb(a.back()+act[i]);
    }
    while(q--){
        int l,r,ans=0;
        cin >> l >> r;
        l--;
        r--;
        int i = l/n, j=r/n;
        l%=n;
        r%=n;
        cout << (j-i+1)*a[n] - (a[i+l]-a[i]) - (a[j+n] - a[j+r+1]) << "\n";
        //indexing can be hard wtf
    }
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
