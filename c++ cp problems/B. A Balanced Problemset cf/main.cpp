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
    int x,n;
    cin >> x >> n;
    int ans = -1;
    for(int i=1;i*i<=x;i++){
        if(x%i != 0) continue;
        if(i<=x/n){
            ans = max(ans,i);
        }
        if(x/i <= x/
           n){
            ans = max(ans, x/i);
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
