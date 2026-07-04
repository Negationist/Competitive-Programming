#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout << gcd(4,9) << "\n";
    return;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
