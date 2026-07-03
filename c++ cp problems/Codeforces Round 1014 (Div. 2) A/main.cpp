#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    int mn = LLONG_MAX, mx = LLONG_MIN;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        if(z>mx){
            mx = z;
        }
        if(z<mn){
            mn = z;
        }
    }
    cout << mx-mn << "\n";
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
