//time 15:00
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
    string s;
    cin >> n >> s;
    vi pref0(n+1),pref1(n+1);
    pref0[0] = pref1[0] = 0;
    for(int i=1;i<=n;i++){
        pref0[i] = pref0[i-1]+(s[i-1]=='0');
        pref1[i] = pref1[i-1]+(s[i-1]=='1');
    }
    set<int> good;
    for(int i=0;i<=n;i++){
        int l = i;
        int r = n-i;
        if(pref0[i] >= (l+1)/2 && pref1[n] - pref1[i] >= (r+1)/2){
            good.insert(i);
        }
    }
    int ans;
    int mn = LLONG_MAX;
    for(int x : good){
        if(abs(n-2*x)<mn){
            mn = abs(n-2*x);
            ans = x;
        }
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
