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
void solve(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    int cost[n*m+5] = {};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            cost[a[i][j]] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i){
                if(a[i][j]==a[i-1][j]){
                    cost[a[i][j]] = 2;
                }
            }
            if(i+1<n){
                if(a[i][j]==a[i+1][j]){
                    cost[a[i][j]] = 2;
                }
            }
            if(j){
                if(a[i][j]==a[i][j-1]){
                    cost[a[i][j]] = 2;
                }
            }
            if(j+1<m){
                if(a[i][j]==a[i][j+1]){
                    cost[a[i][j]] = 2;
                }
            }
        }
    }
    int mx = 0;
    int ans = 0;
    for(int x : cost){
        ans+=x;
        mx = max(mx,x);
    }
    cout << ans-mx << "\n";
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
