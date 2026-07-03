#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
    vi a(m);
    for(int i=0;i<m;i++){
        cin >> a[i];
        if(a[i]==n){
            --a[i];
        }
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int pref[m+1];
    pref[0] = 0;
    for(int i=1;i<=m;i++){
        pref[i] = pref[i-1]+a[i-1];
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        int goal = n-a[i];
        int lo = i+1, hi = m-1;
        bool flag = false;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(a[mid]>=goal){
                flag = true;
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        if(!flag){
            continue;
        } else{
            int num = hi-i;
            int z = pref[hi+1]-pref[i+1];
            int res = z-num*n+num*a[i]+num;
            ans+=res;
        }
    }
    cout << ans*2 << "\n";
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
