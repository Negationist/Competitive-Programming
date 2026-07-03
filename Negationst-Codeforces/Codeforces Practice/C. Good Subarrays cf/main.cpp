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
     string s;
     cin >> s;
     vi a(n);
     map<int,int> m;
     m[0] = 1;
     int inc = 0;
     int sum = 0;
     int ans = 0;
     for(int i=0;i<n;i++){
        sum+=(int)(s[i]-'0');
        ++inc;
        int diff = sum-inc;
        ans+=(m[diff]);
        m[diff]++;
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
