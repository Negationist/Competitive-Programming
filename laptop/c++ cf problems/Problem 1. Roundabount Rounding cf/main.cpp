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
vii dp(11);
vi pref(11);
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


void compute(){
    dp[2] = {45,5};
    for(int i=3;i<11;i++){
        dp[i].ff = dp[i-1].ff+binPow(10LL,i-1)*4;
        dp[i].ss = 5*binPow(10LL,i-1)-dp[i].ff;
    }
    pref[1] = 0;
    for(int i=2;i<11;i++){
        pref[i] = pref[i-1]+dp[i].ss;
    }
}

void solve(){
    int n;
    cin >> n;
    if(n<=44){
        cout << 0 << "\n";
        return;
    }
    int cur = 2;
    for(int i=3;i<11;i++){
        if(n>=dp[i].ff){
            cur = i;
        } else break;
    }
    int res = pref[cur-1]+min(dp[cur].ss, (n-dp[cur].ff+1));
    cout << res << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
