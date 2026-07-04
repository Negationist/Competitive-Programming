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

int binPow(int b, int p){
    int res = 1;
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
    int n,m,x;
    cin >> n >> m >> x;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int b[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[i][j] = (int)(s[i][j]-'0');
        }
    }
    bool flag = false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            int res = binPow(b[i][j]-b[i][j+1],x)+binPow(b[i][j+1]-b[i+1][j+1],x);
            res+=binPow(b[i+1][j+1]-b[i+1][j],x);
            res+=binPow(b[i+1][j]-b[i][j],x);
            if(res){
                flag = true;
            }
        }
    }
    int dp[n][m];
    dp[0][0] = 0;
    for(int i=1;i<m;i++){
        dp[0][i] = dp[0][i-1]+binPow(b[0][i-1]-b[0][i],x);
    }
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]+binPow(b[i-1][0]-b[i][0],x);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int res1 = dp[i-1][j]+binPow(b[i-1][j]-b[i][j],x);
            int res2 = dp[i][j-1]+binPow(b[i][j-1]-b[i][j],x);
            dp[i][j] = min(res1,res2);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(flag && x!=1){
            cout << "INVALID\n";
        } else{
            cout << dp[x2-1][y2-1]-dp[x1-1][y1-1] << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
