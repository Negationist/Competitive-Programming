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
    vi a(n+1);
    int cnt = n/2-1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vi pref1(n+1), pref2(n+1);
    pref1[0] = pref2[0] = 0;
    for(int i=1;i<=n;i++){
        pref1[i] = pref1[i-1]+a[i];
        pref2[i] = pref2[i-1]+a[n+1-i];
    }
    int i = 0,j=cnt;
    int mx = -1;
    while(i<=cnt){
        int res = pref1[i]+pref2[j];
        mx = max(mx,res);
        i++;
        j--;
    }
    int x = pref1[n]-mx;
    int y = mx;
    cout << x << " " << y << "\n";
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
