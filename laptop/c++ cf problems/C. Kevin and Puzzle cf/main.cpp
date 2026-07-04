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

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
int mn = 1, mx = 4;
uniform_int_distribution<int> dist(mn, mx);

const int mod = 998244353;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int dp[n][2] = {};
    dp[0][0] = (a[0]==0);
    dp[0][1] = 1;
    for(int i=1;i<n;i++){
        //last guy is honest
        if(a[i]-a[i-1]==0){
            dp[i][0]+=dp[i-1][0];
        }
        //last guys lies
        if(i!=1 && a[i]-a[i-2]==1){
            dp[i][0]+=dp[i-1][1];
        }
        if(i==1){
            if(a[i]==1){
                dp[i][0]+=dp[i-1][1];
            }
        }
        //we lie
        dp[i][1]+=dp[i-1][0];
        dp[i][0]%=mod;
        dp[i][1]%=mod;
    }
    int ans = dp[n-1][0]+dp[n-1][1];
    cout << ans%mod << "\n";
    /*for(int i=0;i<n;i++){
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    }
    auto check = [&](vi &a){
        int res = 0;
        int z = a.size();
        for(int i=0;i<(1LL<<z);i++){
            vi temp(z);
            for(int j=0;j<z;j++){
                temp[j] = (i&(1LL<<j));
            }
            bool good = true;
            int cnt = 0;
            for(int j=0;j<z;j++){
                if(j>0){
                    if(temp[j] && temp[j-1]){
                        good = false;
                    }
                }
                if(!temp[j] && cnt!=a[j]){
                    good = false;
                }
                cnt+=temp[j];
            }
            if(good){
                ++res;
            }
        }
        return res;
    };
    /*int res = check(a);
    for(int x : a){
        cout << x << " ";
    }
    cout << "\n" << res << " " << ans << "\n";*/
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
