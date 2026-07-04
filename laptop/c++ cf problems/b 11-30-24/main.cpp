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
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        cnt+=(s[i]=='0');
        if(s[i]=='1') cnt = 0;
        if(cnt==m){
            cnt = 0;
            ans++;
            i+=(k-1);
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
