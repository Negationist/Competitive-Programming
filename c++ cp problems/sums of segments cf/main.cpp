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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi b(n+1);
    b[0] = 0;
    for(int i=1;i<n+1;i++){
        b[i] = b[i-1]+a[i-1];
    }
    vi prefb(n+1);
    prefb[0] = 0;
    for(int i=1;i<n+1;i++){
        prefb[i] = prefb[i-1]+b[i];
    }
    vii cSum(n+1);
    cSum[0] = {0,0};
    for(int i=1;i<n+1;i++){
        int index = cSum[i-1].first + (n-i+1); //ONE INDEXED
        int sum = cSum[i-1].second + prefb[n]- prefb[i-1] - b[i-1]*(n-i+1);
        cSum[i] = {index,sum};
    }
    auto psum = [&](int x){
        int l=0,r=n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(cSum[mid].first<=x){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        int rem = x-cSum[r].first;
        int sum = prefb[r+rem] - prefb[r] - b[r]*(rem);
        return cSum[r].second+sum;
    };
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << psum(r)-psum(l-1) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
