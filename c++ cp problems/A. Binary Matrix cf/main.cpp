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
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    int row[n] = {},col[m] = {};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int z = s[i][j]-'0';
            row[i]^=z;
            col[j]^=z;
        }
    }
    int res1 = 0, res2 = 0;
    for(int i=0;i<n;i++) res1+=row[i];
    for(int i=0;i<m;i++) res2+=col[i];
    cout << max(res1,res2) << "\n";
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
