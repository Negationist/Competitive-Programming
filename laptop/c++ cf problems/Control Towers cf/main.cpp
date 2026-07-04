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
    int r,c;
    cin >> r >> c;
    int dp[r][c][4];
    int sum[r][c][4][2];
    vector<string> b(r);
    for(int i=0;i<r;i++){
        cin >> b[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<4;k++){
                if(b[i][j]=='#'){
                    dp[i][j][k] = 0;
                } else{
                    if(k==0){
                        dp[i][j][k] = 1;
                    } else{
                        int res1 = (i?sum[i-1][j][k-1][0]:0);
                        int res2 = (j?sum[i][j-1][k-1][1]:0);
                        dp[i][j][k] = res1+res2;
                    }
                }
                sum[i][j][k][0] = (i?sum[i-1][j][k][0]:0)+dp[i][j][k];
                sum[i][j][k][1] = (j?sum[i][j-1][k][1]:0)+dp[i][j][k];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans+=dp[i][j][3];
        }
    }
    cout << ans*24 << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
