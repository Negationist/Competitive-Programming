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

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i);
    }
}

ld nCr(int n, int r){
    if(n<r) return 0;
    ld res = fact[n]/fact[n-r]/fact[r];
    return res;
}

ld binPow(ld b, int p){
    ld res = 1;
    while(p>0){
        if(p&1){
            res*=b;
        }
        p>>=1;
        b = b*b;
    }
    return res;
}

void solve(){
    //dp[i][j][k] = E.V of longest q with i rooms left to assign, to the first j rooms, longest previous q is q
    //it doesn't matter how likely we are to get to this state as any dp which pulls from this one
    //will have the probablistic cost of only pulling from the first elements already paid
    int n,m;
    cin >> n >> m;
    vi a(m+1);
    for(int i=1;i<=m;i++) cin >> a[i];
    ld dp[n+1][m+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=n;k++){
                if(!i){ //no students, some rooms, q no change
                    dp[i][j][k] = k;
                } else if(i&&!j){ //some students, no rooms, we shouldn't go here but
                    dp[i][j][k] = -1;
                } else if(i && j==1){ //some students, last room
                    int mx = (i+a[j]-1)/a[j];
                    dp[i][j][k] = max(mx,k);
                } else{
                    dp[i][j][k] = 0;
                    for(int c=0;c<=i;c++){
                        int mx = max(k,(c+a[j]-1)/a[j]);
                        ld x = 1/(ld)(j);
                        ld res = dp[i-c][j-1][mx]*nCr(i,c)*binPow(x,c)*binPow(1-x,i-c);
                        dp[i][j][k]+=res;
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(30) << dp[n][m][0] << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    compute();
    solve();
    return 0;
}
