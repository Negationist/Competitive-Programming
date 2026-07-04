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
const int inf = 1LL<<60;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vi> lcp(n, vi(n));
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[i]==s[j]){
                lcp[i][j] = 1;
                if(i+1<n && j+1<n){
                    lcp[i][j]+=lcp[i+1][j+1];
                }
            } else{
                lcp[i][j] = 0;
            }
        }
    }
    vector<vi> dp(n,vi(n));
    vector<vi> mx(n,vi(n));
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i>j){
                dp[i][j] = -inf;
            } else if(j==n-1){
                dp[i][j] = 1;
            } else{
                int len = lcp[i][j+1];
                if(len>=(j-i+1)){
                    int nlen = j-i+1;
                    int index = j+1+nlen;
                    if(index<n){
                        dp[i][j] = 1+mx[j+1][index];
                    } else{
                        dp[i][j] = -inf;
                    }
                } else{
                    int index = j+1+index;
                    if(index==n){
                        dp[i][j] = -inf;
                    } else if(s[i+len] < s[j+1+len]){
                        dp[i][j] = 1+mx[j+1][j+1+len];
                    } else{
                        dp[i][j] = -inf;
                    }
                }
            }
            mx[i][j] = max(dp[i][j],(j!=n-1 ? mx[i][j+1]:-LLONG_MAX));
        }
    }
    int num = mx[0][0];
    cout << num << "\n";
    int l = 0, r = 0;
    while(true){
        while(dp[l][r]!=num) ++r;
        cout << s.substr(l,(r-l+1)) << "\n";
        if(num==1){
            break;
        }
        --num;
        int len = min(lcp[l][r+1],(r-l+1));
        l = r+1;
        r = l+len;
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
