#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    vi p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    int mn = 0, mx = p[1]-p[0];
    for(int i=1;i<n-1;i++){
        int r_mn = p[i-1]+mn, r_mx = p[i-1]+mx;
        int dist = p[i+1] - p[i];
        if(dist > p[i] - r_mx){ //we can connect
            ++ans;
            mn = p[i] - r_mx;
            mx = min(dist, p[i] - r_mn);
        } else{
            mn = 0;
            mx = dist;
        }
    }
    cout << ans+(n>1) << "\n";
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