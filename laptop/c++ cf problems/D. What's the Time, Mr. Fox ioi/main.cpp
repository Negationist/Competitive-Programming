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
    int n,l,q;
    cin >> n >> l >> q;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    while(q--){
        int p,w;
        cin >> p >> w;
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
           if(a[mid]*w > p*a[n-1]){
                hi = mid-1;
           } else{
                lo = mid+1;
           }
        }
        cout << n-lo << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
