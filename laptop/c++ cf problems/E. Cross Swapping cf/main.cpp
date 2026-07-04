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
    vector<vi> a(n,vi(n));
    vi free(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    auto change = [&](int k)->void{
        for(int i=0;i<n;i++){
            swap(a[k][i],a[i][k]);
        }
    };
    vi parity(n,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if()
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " \n"[j==n-1];
        }
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
