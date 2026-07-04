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
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i+1<n;i++){
        if(a[i]>a[i+1]){
            cout << "NO\n";
            return;
        }
        int mn = min(a[i],a[i+1]);
        a[i]-=mn;
        a[i+1]-=mn;
    }
    cout << "YES\n";
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
