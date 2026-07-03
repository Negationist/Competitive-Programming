#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n,m; cin >> n >> m;
    vector<multiset<int>> s(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int z; cin >> z;
            s[j].insert(z);
        }
    }
    set<int> f;
    int num = 0;
    for(int i=0;i<m;i++){
        vi gone;
        for(int x : s[i]){
            auto it = f.upper_bound(x);
            if(it!=f.end()){
                f.erase(it);
                gone.pb(x);
                ++num;
            }
        }
        for(int x : gone) s[i].erase(s[i].find(x));
        for(int x : s[i]) f.insert(x);
    }
    cout << (num>=n?"YES":"NO") << "\n";
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