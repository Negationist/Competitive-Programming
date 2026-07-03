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
    int n,m,k;
    cin >> n >> m >> k;
    int lo = 0, hi = 1e9;
    int mx = k;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(mid>=k){
            if(n/mid>=m+1){
                mx = max(mx,mid);
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        } else{
            int num = n-m*k;
            if(num>=mid){
                mx = max(mx,mid);
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
    }
    if(mx>=k){
        int inc = 0;
        for(int i=0;i<n;i++){
            cout << inc << " ";
            inc = (inc+1)%mx;
        }
    }
    cout << "\n";
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
