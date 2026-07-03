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

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    //if a child is defined you can quickly find what this node is
    //else we can just wait color this one until something above it is defined, only edge case is when the tree is not colored
    int n,k;
    cin >> n >> k;
    vl w(n),c(n);
    for(int i=0;i<n;i++) cin >> w[i];
    for(int i=0;i<n;i++) cin >> c[i];
    vector<vi> adj(n),q(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vector<set<int>> colors(n);
    ll ans = 0;
    auto dfs = [&](auto self, int x, int p)->void{
        int mx = -1, index;
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
                if(mx<sz(colors[y])){
                    mx = sz(colors[y]);
                    index = y;
                }
            }
        }
        if(mx==-1){ //leaf
            if(!c[x]){
                q[x].pb(x);
            } else{
                colors[x].insert(c[x]);
            }
            return;
        }
        colors[x] = move(colors[index]);
        if(c[x]){
            bool fail = false;
            for(int y : adj[x]){
                if(y!=p && y!=index){
                    for(int z : colors[y]){
                        if(colors[x].find(z)!=colors[x].end() && z!=c[x]){
                            fail = true;
                        } else{
                            colors[x].insert(z);
                        }
                    }
                }
                if(y!=p){
                    //cout << x << "is attending to " << y << "\n";
                    for(int z : q[y]){
                        c[z] = c[x];
                    }
                }
            }
            if(fail) ans+=w[x];
            colors[x].insert(c[x]);
        } else{
            if(mx==0){ //all 0 subtree
                q[x] = move(q[index]);
                for(int y : adj[x]){
                    if(y!=p && y!=index){
                        for(int z : q[y]){
                            q[x].pb(z);
                        }
                    }
                }
                q[x].pb(x);
            } else{ //we settle this here and now!
                set<int> cands;
                for(int y : adj[x]){
                    if(y!=p && y!=index){
                        for(int z : colors[y]){
                            if(colors[x].find(z)!=colors[x].end()){
                                cands.insert(z);
                            } else{
                                colors[x].insert(z);
                            }
                        }
                    }
                }
                if(sz(cands)==0){
                    c[x] = *colors[x].begin();
                } else if(sz(cands)==1){
                    c[x] = *cands.begin();
                } else{
                    c[x] = *cands.begin();
                    ans+=w[x];
                }
                for(int y : adj[x]){
                    if(y!=p){
                        for(int z : q[y]){
                            c[z] = c[x];
                        }
                    }
                }
            }
        }
    };
    dfs(dfs,0,-1);
    cout << ans << "\n";
    for(int x : c){
        cout << max(x,1) << " ";
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