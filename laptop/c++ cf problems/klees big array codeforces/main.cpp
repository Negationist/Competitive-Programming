#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k,ans1;
        cin >> n >> k;
        int l = 1, r = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            int lSum = (k+k+mid-1)*(mid/2);
            int rSum = (k+mid+n+k-1)*((n-mid)/2);
            if(lSum <= rSum){
               l = mid+1;
            } else{
                r = mid-1;
            }
        }
        ans1 = ((k+k+r-1)*(r/2)) - ((k+r+n+k-1)*((n-r)/2));
        int ans2 = ((k+k+r)*((r+1)/2)) - ((k+r+n+k)*((n-(r+1)/2)));
        if(ans1 <= ans2){
            cout << r << "\n";
        } else{
            cout << r+1 << "\n";
        }
    }
    return 0;
}
