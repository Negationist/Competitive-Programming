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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi b(n);
    b[0] = a[0];
    for(int i=1;i<n;i++){
        b[i] = b[i-1]+a[i];
    }
    vi prefb(n+1);
    prefb[0] = 0;
    for(int i=1;i<n+1;i++){
        prefb[i] = prefb[i-1]+b[i-1];
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
