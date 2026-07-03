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
void solve(){
    auto lis = [&](vi &a)->int{
        vi dp;
        int len = a.size();
        for(int i=0;i<len;i++){
            int pos = upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
            if(pos==dp.size()){
                dp.pb(a[i]);
            } else{
                dp[pos] = a[i];
            }
        }
        return dp.size();
    };
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
