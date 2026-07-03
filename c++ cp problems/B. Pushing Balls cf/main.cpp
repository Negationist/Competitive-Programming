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
    vector<string> b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    int con[n][m][2] = {};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]=='0') continue;
            if(!i){
                con[i][j][0] = 1;
            } else{
                con[i][j][0] = con[i-1][j][0];
            }
            if(!j){
                con[i][j][1] = 1;
            } else{
                con[i][j][1] = con[i][j-1][1];
            }
            if(!con[i][j][0] && !con[i][j][1]){
                cout << "NO\n";
                return;
            }
        }
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
