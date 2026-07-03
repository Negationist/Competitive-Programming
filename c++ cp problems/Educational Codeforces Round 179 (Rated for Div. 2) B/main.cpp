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
    int n,m;
    cin >> n >> m;
    vi a(n);
    a[0] = 1, a[1] = 2;
    for(int i=2;i<n;i++){
        a[i] = a[i-1]+a[i-2];
    }
    for(int i=0;i<m;i++){
        int w,l,h;
        cin >> w >> l >> h;
        if(min({w,l,h})<a[n-1]){
            cout << 0;
        } else{
            if((a[n-1]+a[n-2])<=max({w,l,h})){
                cout << 1;
            } else{
                cout << 0;
            }
        }
    }
    cout << "\n";
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
