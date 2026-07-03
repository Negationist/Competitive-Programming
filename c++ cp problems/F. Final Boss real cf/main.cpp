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
    int h,n;
    cin >> h >> n;
    int a[n],c[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    int l=1, r=1e11;
    while(l<=r){ //approx constant
        bool good = false;
        int mid = l+(r-l)/2;
        int dmg=0;
        for(int i=0;i<n;i++){ //approx O(n)
            dmg+=a[i];
            int inc = a[i]*((mid-1)/c[i]);
            dmg+=inc;
            if(dmg>=h){
                good = true;
                break;
            }
        }
        if(good){
            r = mid-1;
        } else{
            l = mid+1;
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
