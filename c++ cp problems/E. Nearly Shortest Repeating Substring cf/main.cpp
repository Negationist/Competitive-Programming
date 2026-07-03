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
    int ans = LLONG_MAX;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i!=0) continue;
        int cur = i;
        string k1  = s.substr(0,cur);
        string k2  = s.substr(n-cur,cur);
        int num1 = 0;
        for(int i=0;i<n;i++){
            char x = s[i];
            char y = k1[i%cur];
            num1+=(x!=y);
        }
        int num2 = 0;
        for(int i=0;i<n;i++){
            char x = s[i];
            char y = k2[i%cur];
            num2+=(x!=y);
        }
        if(num1<2 || num2<2){
            ans = min(ans,cur);
        }
        cur = n/i;
        string l1  = s.substr(0,cur);
        string l2  = s.substr(n-cur,cur);
        num1 = 0;
        for(int i=0;i<n;i++){
            char x = s[i];
            char y = l1[i%cur];
            num1+=(x!=y);
        }
        num2 = 0;
        for(int i=0;i<n;i++){
            char x = s[i];
            char y = l2[i%cur];
            num2+=(x!=y);
        }
        if(num1<2 || num2<2){
            ans = min(ans,cur);
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
