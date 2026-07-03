#include <bits/stdc++.h>
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
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n; cin >> n;
    vector<vi> adj(n, vi());
    for(int i=1;i<n;i++){
        int z; cin >> z; --z;
        adj[z].pb(i);
        adj[i].pb(z);
    }
    int ans = n;
    auto dfs = [&](auto self, int x, int p)->int {
        vi d;
        bool leaf = true;
        for(int y : adj[x]){
            if(y!=p){
                int res = self(self, y, x);
                d.pb(res);
                leaf = false;
            }
        }
        if(leaf){
            return 1;
        }
        sort(all(d));
        if(sz(d) > 1){
            ans+=d[sz(d)-2];
        }
        return d.back()+1;
    };
    dfs(dfs, 0, -1);
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
