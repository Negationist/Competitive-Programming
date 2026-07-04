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
    double x,y,k;
    cin >> x >> y >> k;
    int xmin = ceil(x/k);
    int ymin = ceil(y/k);
    if(xmin < ymin){
        xmin = ymin;
    } else if(xmin > ymin){
        ymin = xmin -1;
    }
    cout << xmin+ymin << "\n";
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
