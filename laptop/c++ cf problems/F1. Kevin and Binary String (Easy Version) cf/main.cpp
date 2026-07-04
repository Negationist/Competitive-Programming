#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    vi a,b;
    int cnt1 = 1, cnt2 = 1;
    for(int i=1;i<n;i++){
        if(s1[i]==s1[i-1]){
            cnt1++;
        } else{
            a.pb(cnt1);
            cnt1 = 1;
        }
        if(s2[i]==s2[i-1]){
            cnt2++;
        } else{
            b.pb(cnt2);
            cnt2 = 1;
        }
    }
    a.pb(cnt1);
    b.pb(cnt2);
    int ans = 0, x = 0, y = 0, j = 0; //x is '0'
    if(s1[0]!=s2[0]){
        ++ans;
        ++j;
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
