
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
    int k;
    cin >> k;
    unsigned long long l=0,r=1e19;
    while(l<=r){
        int mid = l+(r-l)/2;
        int take = sqrtl(mid);
        int num = mid-take;
        if(num < k){
           l = mid+1;
        } else{
            r = mid - 1;
        }
    }
    cout << r+1 << "\n";
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
