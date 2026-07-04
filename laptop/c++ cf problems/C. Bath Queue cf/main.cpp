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
const int maxN = 60;
vector<ld> fact(maxN);
int nCr(int n, int r){
    if(n<r){
        return 0;
    }
    ld res = fact[n]/fact[n-r]/fact[r];
    return res;
}

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = fact[i-1]*i;
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<ld> a(m);
    ld dp[m][n+1][n+1];
    ld sum[m][n+1][n+1];
    ld tot = 0;
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(!i){
                    int sze = (k+a[i]-1)/a[i];
                    if(sze==j){
                        dp[i][j][k] = nCr(n,k);
                    } else{
                        dp[i][j][k] = 0;
                    }
                } else if(!k && !j){
                    dp[i][j][k] = 1;
                } else{
                    dp[i][j][k] = dp[i-1][j][k];
                    int mn = a[i]*(j-1)+1, mx = a[i]*j;
                    for(int l=mn;l<=mx;l++){
                        if(k-l<0) break;
                        ld res1 = sum[i-1][j][k-l]; //j<=j, k'<=k-l
                        if(k-l-1>=0) res1-=sum[i-1][j][k-l-1]; //exatly k-l members, j'<=j
                        ld res2 = res1*nCr(n-(k-l),l);
                        dp[i][j][k]+=res2;
                    }
                    if(k-mn>=0){
                        dp[i][j][k]+=sum[i-1][j][k-mn];
                    }
                    if(k-mx-1>=0){
                        dp[i][j][k]-=sum[i-1][j][k-mx-1];
                    }
                }
                sum[i][j][k] = (j?sum[i][j-1][k]:0)+(k?sum[i][j][k-1]:0);
                sum[i][j][k]-=(j&&k?sum[i][j-1][k-1]:0);
                sum[i][j][k]+=dp[i][j][k];
                if(k==n && i==m-1){
                    tot+=dp[i][j][k];
                }
                cout << "dp " << i << " " << j << " " << k << " is " << dp[i][j][k] << "\n";
            }
        }
    }
    ld ev = 0;
    for(int i=0;i<=n;i++){
        ld num1 = sum[m-1][i][n]-(i?sum[m-1][i-1][n]:0); //all dp with max queue of i and j<=n
        ld num2 = sum[m-1][i][n-1]-(i?sum[m-1][i-1][n-1]:0); //all dp with max queue of i and j<=n-1
        ld num3 = num1-num2;
        cout << "number of max q " << i << "is " << num3 << "\n";
        ld res = (num3/tot)*i;
        ev+=res;
    }
    cout << fixed << setprecision(16) << ev << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    compute();
    solve();
    return 0;
}
