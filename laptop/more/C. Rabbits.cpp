#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vi a;
    int cnt = 1, flag = s[0] - '0';
    //0 -> 0, 1 -> 1, 00 -> 2, 11 -> 3
    for(int i=1;i<n;i++){
        if(flag + '0' == s[i]){
            ++cnt;
        }  else{
            if(cnt == 1){
                a.pb(flag);
            } else{
                a.pb(flag + 2);
            }
            cnt = 1;
            flag = 1 - flag;
        }
    }
    if(cnt == 1){
        a.pb(flag);
    } else{
        a.pb(flag + 2);
    }
    n = (int)(a.size());
    int dp[n][2] = {};
    for(int i=0;i<n;i++){
        int last = i-2;
        if(a[i] == 0){
            if(last<0){ //base case
                dp[i][0] = 1;
                if(i==0){
                    dp[i][1] = 1;
                }
            } else{
                dp[i][0] = dp[last][1];
                dp[i][1] = (dp[last][0] && a[i-1]==1);
            }
            //cout << dp[i][0] << " " << dp[i][1] << "!!\n";
        } else if(a[i] == 2){
            if(last<0){ //base case
               dp[i][0] = dp[i][1] = 1;
            } else{
                if((dp[last][0] && a[i-1] == 1) || dp[last][1]){
                    dp[i][0] = dp[i][1] = 1;
                } else{
                    dp[i][0] = dp[i][1] = 0;
                }
            }
            //cout << dp[i][0] << " " << dp[i][1] << "!!\n";
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i] == 0 || a[i] ==  2){
            if(dp[i][1] || (dp[i][0] && i==n-1)){
                break;
            } else{
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