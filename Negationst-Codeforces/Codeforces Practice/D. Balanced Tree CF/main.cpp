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
    auto dfs2 = [&](auto self, int x, int p)->int{ //returns the carry
        vi temp;
        int carry = 0;
        int mx = -1;
        for(int y : adj[x]){
            if(y!=p){
                carry+=self(self,y,x);
                mx = max(mx,val[y]);
                temp.pb(val[y]);
            }
        }
        val[x]+=carry;
        if(mx<=val[x]){
            //cout << "val " << x+1 << " is " << val[x] << ". carry is " << carry << "\n";
            return carry;
        } else{
            int carry2 = 0;
            for(int k : temp){
                if(k>val[x]){
                    carry2+=(k-val[x]);
                }
            }
            val[x]+=carry2;
            carry+=carry2;
            //cout << "val " << x+1 << " is " << val[x] << ". carry is " << carry2 << "\n";
            return carry;
        }
    };
    dfs2(dfs2,0,-1);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,val[i]);
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
