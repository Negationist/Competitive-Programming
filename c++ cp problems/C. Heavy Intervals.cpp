#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vl vector<long long>
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
    set<int> l,r;
    vi c(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        l.insert(z);
    }
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        r.insert(z);
    }
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    vi len;
    for(int x : r){
        auto it = l.lower_bound(x);
        it--;
        len.pb(x-(*it));
        l.erase(it);
    }
    sort(all(len));
    sort(rall(c));
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans+=((ll)(len[i])*c[i]);
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