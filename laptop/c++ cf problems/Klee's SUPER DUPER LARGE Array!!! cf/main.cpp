#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int aSum(int f, int l){
    int num = l-f+1;
    return (l+f)*(num)/2;
}

void solve(){
    int n,k;
    cin >> n >> k;
    int l=1, r = n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        int lSum = aSum(k,k+mid-1);
        int rSum = aSum(k+mid,n+k-1);
        if(lSum <= rSum){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    int ans1 = abs(aSum(k,k+r-1)-aSum(k+r,n+k-1));
    r++;
    int ans2 = abs(aSum(k,k+r-1)-aSum(k+r,n+k-1));
    cout << min(ans1, ans2) << "\n";
}

signed main()
{

   // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
