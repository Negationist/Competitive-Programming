#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,m;
    cin >> n >> m;
    cout << "YES\n";
    cout << 2*m << "\n";
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cout << a << " " << b << " ";
        for(int j=1;j<=n;j++){
            if(j!=a && j!=b){
                cout << j << " ";
            }
        }
        cout << "\n";
        for(int j=n;j>=1;j--){
            if(j!=a && j!=b){
                cout << j << " ";
            }
        }
        cout << a << " " << b << " ";
        cout << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
