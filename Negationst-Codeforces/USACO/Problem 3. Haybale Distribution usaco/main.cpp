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
    vii d(n);
    int tL = 0, tR = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        tR+=(a[i]-a[0]);
    }
    d[0] = {tL,tR};
    int l = 1, r =n-1;
    for(int i=1;i<n;i++){
        int diff = a[i]-a[i-1];
        tR-=(r*diff);
        tL+=(l*diff);
        d[i] = {tL,tR};
        l++;
        r--;
    }
    int q;
    cin >> q;
    while(q--){
        if(n==1){
            cout << 0 << "\n";
        }
        int a,b;
        cin >> a >> b;
        int i = (long double)(b*n)/(a+b);
        int ans1 = a*(d[i].ff)+b*(d[i].ss);
        cout << ans1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
