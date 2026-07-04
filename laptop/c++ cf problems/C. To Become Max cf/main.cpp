#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    int ans = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ans = max(ans,a[i]);
    }
    for(int i=0;i<n-1;i++){
        int l = a[i], r=2e8;
        while(l<=r){
            int cnt = k;
            int mid = l+(r-l)/2;
            cnt-=(mid-a[i]);
            int cur = mid;
            for(int j=i+1;j<n;j++){
                int need = cur-1;
                if(j==n-1){
                    if(a[j]<need){
                        cnt = -1;
                    }
                } else{
                    if(a[j]>=need) break;
                    else{
                        int diff = need-a[j];
                        cnt-=diff;
                        cur = need;
                    }
                }
            }
            if(cnt>=0){
                l = mid+1;
                ans = max(ans,mid);
            } else{
                r = mid-1;
            }
        }
    }
    cout << ans << "\n";
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
