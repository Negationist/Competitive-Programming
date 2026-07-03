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
    if(k >= 3){
        cout << "0\n";
        return;
    }
    sort(a.begin(), a.end());
    if(k==2){
        int mn = a[0];
        for(int i=0;i<n-1;i++){
            for(int j=1; j+i <n; j++){
                int diff = a[i+j]-a[i];
                int l=0, r=n-1;
                while(l<=r){
                    int mid = l +(r-l)/2;
                    if(a[mid]<=diff){
                        l = mid+1;
                    } else{
                        r = mid-1;
                    }
                }
                if(r>=0) {
                    mn = min(mn, diff-a[r]);
                }
                if(r+1<n) {
                    mn = min(mn, a[r+1] - diff);
                }
                mn = min(mn, diff);
            }
        }
        cout << mn << "\n";

    }
    if(k==1){
        int mn = a[0];
        for(int i=0;i<n-1;i++){
            mn = min(mn, a[i+1]-a[i]);
        }
        cout << mn << "\n";
        return;
    }

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
