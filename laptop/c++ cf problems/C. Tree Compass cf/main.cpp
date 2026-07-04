#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    if(n==1){
        cout << "1\n1 0\n";
        return;
    }
    int mx = -1;
    int node;
    vi pa(n,-1);
    auto dfs = [&](auto self, int x, int p, int d)->void{
        pa[x] = p;
        if(d>mx){
            mx = d;
            node = x;
        }
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x,d+1);
            }
        }
    };
    dfs(dfs,0,-1,0);
    int root = node;
    mx = -1;
    dfs(dfs,root,-1,0);
    int leaf = node;
    vi path;
    int cur = leaf;
    while(cur!=-1){
        path.pb(cur);
        cur = pa[cur];
    }
    int len = path.size();
    if(len%4!=0){
        int mid = (len+1)/2;
        int target = path[mid-1];
        int max_d = len-mid;
        cout << max_d+1 << "\n";
        for(int i=0;i<=max_d;i++){
            cout << target+1 << " " << i << "\n";
        }
    } else{
        int mid = (len+1)/2;
        int t1 = path[mid-1];
        int t2 = path[mid];
        int dis = 1;
        cout << (len/4)*2 << "\n";
        while(len>0){
            cout << t1+1 << " " << dis << "\n";
            cout << t2+1 << " " << dis << "\n";
            len-=4;
            dis+=2;
        }
    }
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
