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
    int r,c;
    cin >> r >> c;
    vector<string> b(r);
    for(int i=0;i<r;i++) cin >> b[i];
    int dp[r][c][4],row[r][4]={},col[c][4]={};
    int sum[4] = {};
    for(int k=0;k<4;k++){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(b[i][j]=='#'){
                    dp[i][j][k] = 0;
                } else{
                    if(!k){
                        dp[i][j][k] = 1;
                    } else{
                        dp[i][j][k] = row[i][k-1]+col[j][k-1]-2*dp[i][j][k-1];
                    }
                }
                row[i][k]+=dp[i][j][k];
                col[j][k]+=dp[i][j][k];
                sum[k]+=dp[i][j][k];
            }
        }
    }
    int ans = sum[3]-2*sum[2]+sum[1];
    for(int i=0;i<r;i++){
        int num = 0;
        for(int j=0;j<c;j++){
            num+=(b[i][j]=='.');
        }
        if(num>=3){
            ans-=(num*(num-1)*(num-2));
        }
    }
    for(int j=0;j<c;j++){
        int num = 0;
        for(int i=0;i<r;i++){
            num+=(b[i][j]=='.');
        }
        if(num>=3){
            ans-=(num*(num-1)*(num-2));
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
