#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
vector<int> square(64);
void compute(){
    square[0] = 1;
    for(int i=1;i<64;i++){
        square[i] = square[i-1]*2;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<long double> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    int cnt = 1;
    for(int i=1;i<n;i++){
        long double res = cnt*log(a[i-1])/log(a[i]);
        cout << "res is " << res << "\n";
        int cur = ceil(res);
        if(cur==1){
            cnt = 1;
            continue;
        }
        int l = 0,r=63;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(square[mid]<=cur){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        cnt = r;
        ans+=cnt;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    compute();
    while(t--){
        solve();
    }
    return 0;
}
