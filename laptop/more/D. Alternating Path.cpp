#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,m; cin >> n >> m;
    vector<vi> adj(n, vi());
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vi color(n);
    int num, b,ans = 0;
    bool fail;
    for(int i=0;i<n;i++) color[i] = 2;
    auto dfs = [&](auto self, int x, int tag)->void {
        ++num;
        color[x] = tag;
        if(tag == 0) ++b;
        //cout << "up!\n";
        //cout << fail << "!!\n";
        for(int y : adj[x]){
            if(color[y] == 2){
                self(self, y, 1-tag);
            } else{
                if(color[x] ^ color[y] == 0) fail = 1;
            }
        }
        //cout << fail << "!!\n";
    };
    for(int i=0;i<n;i++){
        num = b = 0;
        fail = 0;
        if(color[i] == 2){
            dfs(dfs, i, 0);
            //cout << fail << "!\n";
            if(!fail) ans+=(max(b, num-b));
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