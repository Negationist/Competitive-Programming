#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n,m;
    cin >> n >> m;
    vi b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    vector<pair<pii,int>> p(m);
    for(int i=0;i<m;i++){
        cin >> p[i].ff.ff >> p[i].ff.ss >> p[i].ss;
    }
    sort(p.begin(),p.end(),
         [&](const pair<pii, int>& a, const pair<pii, int>& b){
            return (a.ff.ss < b.ff.ss);
            });
    auto check = [&](int z){
        vi dp(n+1,-1);
        dp[1] = min(b[0],z);
        for(auto x : p){
            int l = x.ff.ff, r = x.ff.ss, w = x.ss;
            if(dp[l]==-1 || dp[l]<w){
                continue;
            } else{
                dp[r] = max(dp[r],min(dp[l]+b[r-1],z));
            }
        }
        /*for(int i=1;i<=n;i++){
            cout << "dp" << i << " is " << dp[i] << "\n";
        }*/
        return (dp[n]!=-1 && dp[n]<=z);
    };
    int lo = 0, hi = 1e9;
    bool flag = false;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)){
            flag = true;
            hi = mid-1;
        } else{
            lo = mid+1;
        }
    }
    cout << (flag?lo:-1) << "\n";
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
