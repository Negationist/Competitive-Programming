#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
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
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    for(int i=1;i<=n;i++){
        int l = 0, r = 0, seen = 0;
        for(int j=0;j<n;j++){
            if(a[j]>i){
                if(seen){
                    ++r;
                } else{
                    ++l;
                }
            } else if(a[j]==i){
                seen = 1;
            }
        }
        ans+=min(l,r);
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