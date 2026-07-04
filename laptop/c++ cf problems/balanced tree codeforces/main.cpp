#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vii r(n);
    for(int i=0;i<n;i++){
        cin >> r[i].ff >> r[i].ss;
    }
    vector<vi> adj(n);
    vi val(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    auto dfs1 = [&](auto self, int x, int p)->void{
        int mx = -1;
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
                mx = max(mx,val[y]);
            }
        }
        if(mx==-1){
            val[x] = r[x].ff;
        } else{
            if(r[x].ss < mx){
                val[x] = r[x].ss;
            } else if(r[x].ff > mx){
                val[x] = r[x].ff;
            } else{
                val[x] = mx;
            }
        }
    };
    dfs1(dfs1,0,-1);
    vi ogval = val;
    auto dfs2 = [&](auto self, int x, int p)->int{ //returns the carry
        vi temp;
        int carry1 = 0;
        for(int y : adj[x]){
            if(y!=p){
                carry1+=self(self,y,x);
                temp.pb(ogval[y]);
            }
        }
        val[x]+=carry1;
        int carry2 = 0;
        for(int k : temp){
            if(k>ogval[x]){
                carry2+=(k-ogval[x]);
            }
        }
        val[x]+=carry2;
        return carry1+carry2;
    };
    dfs2(dfs2,0,-1);
    cout << val[0] << "\n";
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
