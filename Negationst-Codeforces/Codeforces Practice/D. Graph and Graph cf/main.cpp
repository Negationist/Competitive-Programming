#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using u128 = unsigned __int128;
const int inf = 1LL<<60;
void solve(){
    string x;
    unsigned long long b;
    cin >> x >> b;
    int n = x.size();
    if(x[0]=='0'){
        cout << "0\n";
        return;
    }
    vector<vi> dp(n,vi(20,inf));
    vector<vi> mn(n,vi(20,inf));
    for(int i=n-1;i>=0;i--){
        u128 tot = 0;
        for(int j=0;j<20 && i+j<n;j++){
            if(x[i]=='0'){
                continue;
            }
            tot = 10*tot+(x[i+j]-'0');
            if(tot>b){
                continue;
            }
            if(i+j==n-1){
                dp[i][j] = 0;
            } else{
                u128 otot = 0;
                int len = -1;
                while(otot<tot && i+j+1+len<n){
                    ++len;
                    otot = otot*10+(x[i+j+1+len]-'0');
                }
                if(otot>=tot){
                    dp[i][j] = 1+mn[i+j+1][len];
                }
            }
        }
        mn[i][19] = dp[i][19];
        for(int j=18;j>=0;j--){
            mn[i][j] = min(mn[i][j+1],dp[i][j]);
        }
    }
    if(mn[0][0]!=inf){
        cout << mn[0][0]<< "\n";
    } else{
        cout << "NO WAY\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
