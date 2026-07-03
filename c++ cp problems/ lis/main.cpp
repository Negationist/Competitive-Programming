#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi dp;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        int pos = lower_bound(dp.begin(),dp.end(),z)-dp.begin();
        if(pos==dp.size()){
            dp.pb(z);
        } else{
            dp[pos] = z;
        }
    }
    cout << dp.size() << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
