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
    int n,k;
    cin >> n >> k;
    int a[n];
    int GCD;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0) GCD = a[0];
        else GCD = gcd(GCD, a[i]);
    }
    if(n==1){
        int ans = k-1;
        if(ans>=a[0]){
            ans++;
        }
        cout << ans << "\n";
        return;
    }
    int mex = k-1;
    for
        (int i=0;i<n;i++){
        if(mex >= i*GCD){
            mex++;
        }
    }
    cout << mex << endl;
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
