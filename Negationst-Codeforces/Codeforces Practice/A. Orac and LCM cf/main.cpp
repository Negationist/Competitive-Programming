#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi pref(n),suff(n);
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = gcd(pref[i-1],a[i]);
    }
    suff[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i] = gcd(suff[i+1],a[i]);
    }
    int ans = 1;
    for(int i=0;i<n;i++){
        int cur;
        if(i==0){
            cur = suff[1];
        } else  if(i==n-1){
            cur = pref[n-2];
        } else{
            cur = gcd(pref[i-1],suff[i+1]);
        }
        ans = ans*cur/gcd(ans,cur);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
