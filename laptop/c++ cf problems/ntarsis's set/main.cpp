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
    int x,y,r;
    cin >> x >> y >> r;
    cout << x+r << " " << y+r << "\n";
    cout << x-r << " " << y+r << "\n";
    cout << x-r << " " << y-r << "\n";
    cout << x+r << " " << y-r << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
