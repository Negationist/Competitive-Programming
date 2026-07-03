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

void solve(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> seg(n);
    for(int i=0;i<n;i++){
        cin >> seg[i].ff >> seg[i].ss;
    }
    vector<pair<ll,ll>> u_segs;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll l1 = max(seg[i].ff, seg[j].ff), r1 = min(seg[i].ss, seg[j].ss);
            if(l1<=r1){
                u_segs.pb({min(seg[i].ff, seg[j].ff),max(seg[i].ss, seg[j].ss)});
            }
        }
    }
    u_segs.pb({-1,-1});
    seg = move(u_segs);
    sort(seg.begin(),seg.end(),
         [](pair<ll,ll> &i, pair<ll,ll> &j){
                if(i.ss != j.ss){
                    return i.ss<j.ss;
                }
            }
         );
    int ans = n;
    n = seg.size();
    int dp[n];
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int lo = 0, hi = i-1, l = seg[i].ff;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(seg[mid].ss<l){
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        dp[i] = max(dp[i-1],1+dp[hi]);
    }
    cout << ans-2*dp[n-1] << "\n";
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
