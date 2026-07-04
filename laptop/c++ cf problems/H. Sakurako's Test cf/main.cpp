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
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,q;
    cin >> n >> q;
    vi cnt(2*n+5,0);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        cnt[z]++;
    }
    for(int i=1;i<2*n+5;i++){
        cnt[i]+=cnt[i-1];
    }
    int ans[n+5];
    for(int i=1;i<=n;i++){
        int lo = 0, hi = i-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int num = 0;
            //cout << mid << "!\n";
            for(int k=0;k*i<=n;k++){
                num+=(cnt[k*i+mid]-(k*i?cnt[k*i-1]:0));
            }
            if(num*2>n){
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        ans[i] = lo;
    }
    while(q--){
        int x;
        cin >> x;
        cout << ans[x] << " ";
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
