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
    int l,r,g;
    cin >> l >> r >> g;
    int x = l+g-1/g;
    int y = r/g;
    bool maybe = (x>=l && x<=r && y>=l && y<=r);
    if(!maybe){
        cout << "-1 -1\n";
        return;
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
