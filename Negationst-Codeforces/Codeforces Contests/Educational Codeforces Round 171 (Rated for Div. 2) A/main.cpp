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
    int x,y,k;
    cin >> x >> y >> k;
    int mn = min(x,y);
    cout << 0 << " " << 0 << " " << mn << " " << mn << "\n";
    cout << 0 << " " << y << " " << 0+mn << " " << y-mn << "\n";
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
