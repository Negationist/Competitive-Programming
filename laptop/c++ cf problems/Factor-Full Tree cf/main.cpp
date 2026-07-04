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
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vi val(n,-1),pa(n);
    auto dfs1 = [&](auto self, int x, int p)->void{
        if(p!=-1){
            pa[x] = p;
        }
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
            }
        }
    };
    dfs1(dfs1,0,-1);
    val[0] = 1;
    int node,mx,prime=2;
    auto dfs2 = [&](auto self, int x, int p, int dist)->void{
        if(val[x]!=-1){
           dist = 0;
        } else{
            //cout << x+1 << " has " << dist << "\n";
            if(dist>mx){
                mx = dist;
                node = x;
            }
        }
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x,dist+1);
            }
        }
    };
    while(true){
        mx = node = -1;
        dfs2(dfs2,0,-1,0);
        if(node==-1) break;
        //cout << node << "!\n";
        vi nodes;
        int cur = node;
        while(val[cur]==-1){
            nodes.pb(cur);
            cur = pa[cur];
        }
        reverse(nodes.begin(),nodes.end());
        int base = val[cur];
        for(int x : nodes){
            base*=prime;
            val[x] = base;
        }
        ++prime;
        while(true){
            bool flag = false;
            for(int i=2;i<=sqrt(prime);i++){
                if(prime%i==0){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ++prime;
            } else{
                break;
            }
        }
    }
    for(int x : val){
        cout << x << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
