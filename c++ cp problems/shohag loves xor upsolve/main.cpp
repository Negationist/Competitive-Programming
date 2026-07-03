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
    int x,m;
    cin >> x >> m;
    int ans = (m-x)/x+1;;
    if(m-x>=x || m-x<0) ans--;
    for(int i=m+x-(m+x)%x;i>m-x;i-=x){
        int res = i^x;
        if(res<=m && res>=1){
            ans++;
        }
    }
    for(int i=1;i<=min(x,m);i++){
        int res = i^x;
        if(res%i==0){
            ans++;
        }
    }
    cout << ans-(m>=x) << "\n";
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
