#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n; cin >> n;
    if(n==0){
        cout << "YES\n";
        return;
    }
    while(n%2==0){
        n/=2;
    }
    vi s;
    while(n){
        s.pb(n%2);
        n/=2;
    }
    vi t = s;
    reverse(t.begin(),t.end());
    if(s == t){
        n = (int)(t.size());
        if(n%2==0){
            cout << "YES\n";
            return;
        } else{
            if(t[n/2] == 0){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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