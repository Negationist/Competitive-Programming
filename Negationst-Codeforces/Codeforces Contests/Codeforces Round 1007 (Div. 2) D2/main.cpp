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
    vi a(n+1),prefxor(n+1);
    a[0] = prefxor[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        prefxor[i] = prefxor[i-1]^a[i];
    }
    for(int i=n+1;i<=n+25;i++){
        int last = i/2;
        int res = 0;
        for(int i=1;i<=last;i++){
            res^=a[i];
        }
        a.pb(res);
        cout << i << " is " << res << "\n";
    }
    cout << "!\n";
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
