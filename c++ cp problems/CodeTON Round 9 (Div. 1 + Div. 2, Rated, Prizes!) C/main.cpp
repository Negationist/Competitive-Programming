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
    int ans = 0;
    for(int i=1;i<=2*x;i++){
        int res = x^i;
        if(res==0) continue;
        if(i%res==0 || x%res==0){
            if(i<=m){
                ans++;
            }
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
