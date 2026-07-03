#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
//thanks tibinyte
void solve(){
    int n,ans;
    deque<pii> dq;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int mex = 0;
    int sum = 0;
    int pres[n+1] = {};
    for(int i=0;i<n;i++){
        pres[a[i]]++;
        while(pres[mex]){
            mex++;
        }
        dq.push_back({mex,1});
        sum+=mex;
    }
    ans = sum;
    for(int i=0;i<n;i++){
        sum-=dq.front().first;
        dq.front().second--;
        if(dq.front().second==0){
            dq.pop_front();
        }
        pair<int,int> last = {a[i],0};
        while(dq.size() && a[i]<=dq.back().first){
            last.second+=dq.back().second;
            sum-=(dq.back().second * dq.back().first);
            dq.pop_back();
        }
        sum+=(a[i]*last.second);
        sum+=n;
        ans = max(ans, sum);
        dq.pb(last);
        dq.pb({n,1});
    }
    cout << ans << "\n";
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
