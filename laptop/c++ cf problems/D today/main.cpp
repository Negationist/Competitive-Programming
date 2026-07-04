#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

pii dp[60][60];
const int inf = 1LL<<30;
void compute(){
    dp[0][0] = {0,0};
    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++){
            if(!i && !j) continue;
            dp[i][j] = {inf,inf};
            for(int k=1;k<=60;k++){
                if(i-k>=0){
                    if(k>dp[i-k][j].ff){
                        int res = dp[i-k][j].ss+(1LL<<k);
                        if(k<=dp[i][j].ff){
                            dp[i][j] = {k,min(dp[i][j].ss,res)};
                        }
                    }
                }
                if(j-k>=0){
                    if(k>dp[i][j-k].ff){
                        int res = dp[i][j-k].ss+(1LL<<k);
                        if(k<=dp[i][j].ff){
                            dp[i][j] = {k,min(dp[i][j].ss,res)};
                        }
                    }
                }
            }
        }
    }
}

void solve(){
    int a,b;
    cin >> a >> b;
    string x,y;
    while(a){
        x.pb((a&1?'l':'0'));
        a>>=1;
    }
    while(b){
        y.pb((b&1?'l':'0'));
        b>>=1;
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int j = 0;
    int mn = min(x.size(),y.size());
    while(j<mn && x[j]==y[j]){
        ++j;
    }
    int c1 = x.size()-j, c2 = y.size()-j;
    int ans = LLONG_MAX;
    while(c1<60 && c2<60){
        ans = min(ans,dp[c1][c2].ss);
        ++c1;
        ++c2;
    }
    if(c1==c2){
        int l = x.size()+1, m = y.size();
        ans = min(ans, (1LL<<l)+(1LL<<m));
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    compute();
    //cout << dp[2][0].ss << "!\n";
    while(t--){
        solve();
    }
    return 0;
}
