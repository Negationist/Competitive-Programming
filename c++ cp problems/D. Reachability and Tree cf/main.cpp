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
void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n,vi());
    vii edges;
    vi val(n);
    int root;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
        edges.pb({a,b});
    }
    if(n==2){
        cout << "NO\n";
        return;
    }
    for(int i=0;i<n;i++){
        if((int)adj[i].size()==1){
            root = i;
        }
    }
    auto dfs = [&](auto self, int x, int p, int color)->void{
        val[x] = color;
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x,!color);
            }
        }
    };
    dfs(dfs,root,-1,0);
    cout << "YES\n";
    for(auto [x,y] : edges){
        if(x==root){
            cout << y+1 << " " << x+1 << "\n";
        } else if(y==root){
            cout << x+1 << " " << y+1 << "\n";
        } else{
            if(val[x]==0){
                cout << x+1 << " " << y+1 << "\n";
            } else{
                cout << y+1 << " " << x+1 << "\n";
            }
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
