#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int inf = 1LL<<(63);

void solve(){
    int x,m;
    cin >> x >> m;
    int l=2, r= LLONG_MAX/x;
    while(l<=r){
        int mid = l+(r-l)/2;
        int res = (mid*x)^x;
        if(res<=m){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    int ans = (r-1);
    for(int i=r;i>=max(r-10,2LL);i--){
        int res = (i*x)^x;
        if(res>m){
            ans--;
        }
    }
    for(int i=r+1;i<r+10;i++){
        int res = (i*x)^x;
        if(res<=m){
            ans++;
        }
    }
    ans = max(ans,0LL);
    int mn = (2*x)^x;
    for(int i=1;i<=min(m,2*x+5);i++){
        int cur = x^i;
        if(cur%i==0){
            if(cur%x!=0){
                ans++;
            } else if(i<mn){
                ans++;
            }
        }
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
