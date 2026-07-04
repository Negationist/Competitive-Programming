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
    int n,m;
    cin >> n >> m;
    int num = 0, taken = 0;
    int b[n][m], ptr[n] = {};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
            num+=b[i][j];
            sum[i]+=b[i][j];
        }
    }
    cout << (num/2)*((num+1)/2) << "\n";
    for(int i=n-1;i>=0;i--){
        int 
        if(taken < num/2){

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