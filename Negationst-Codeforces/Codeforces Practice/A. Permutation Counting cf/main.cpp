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
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    a.pb(1LL<<40);
    sort(a.begin(),a.end());
    int mn = a[0];
    int index = 0;
    for(int i=0;i<n;i++){
        index = i;
        int diff = a[i+1]-mn;
        int cost = diff*(i+1);
        if(k-cost>=0){
            k-=cost;
            mn = a[i+1];
        } else{
            int l=0, r=diff;
            while(l<=r){
                int mid = l+(r-l)/2;
                int costt = mid*(i+1);
                if(costt<=k){
                    l = mid+1;
                } else{
                    r = mid-1;
                }
            }
            mn = a[i]+r;
            k-=(r*(i+1));
            break;
        }
    }
    int ans = mn*n+1-(index+1)+k;
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
