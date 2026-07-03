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
    map<pii,pii> m;
    vii c(n);
    vii seg;
    for(int i=0;i<n;i++){
        cin >> c[i].ff >> c[i].ss;
        int l = c[i].ff-c[i].ss;
        int r = c[i].ff+c[i].ss;
        m[{l,r}] = c[i];
        seg.pb({l,r});
    }
    sort(seg.begin(), seg.end(),
         [](const pii &a, const pii &b) {
             if (a.ff != b.ff) return a.ff < b.ff;
             return a.ss > b.ss;
    });
    vi dp;
    vector<tuple<int,int,int>> out;
    for(int i=n-1;i>=0;i--){
        int cur = seg[i].ss;
        int ans;
        bool mn = true;
        int l = 0, r = dp.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(dp[mid]<=cur){
                r = mid-1;
                mn = false;
            } else{
                l = mid+1;
            }
        }
        if(mn){
            dp.pb(cur);
            ans = dp.size();
        } else{
            dp[l] = cur;
            ans = l+1;
        }
        out.pb({m[seg[i]].ff, m[seg[i]].ss, ans});
    }
    cout << dp.size() << "\n";
    for(auto x : out){
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
