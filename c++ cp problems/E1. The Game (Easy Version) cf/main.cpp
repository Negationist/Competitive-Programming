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
    vi a(n);
    vector<vi> adj(n);
    vector<multiset<int>> mxs(n);
    vi mxout(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    auto dfs1 = [&](auto self, int x, int p)->void{
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
                mxs[x].insert(*mxs[y].rbegin());
            }
        }
        mxs[x].insert(a[x]);
    };
    dfs1(dfs1,0,-1);
    auto dfs2 = [&](auto self, int x, int p)->void{
        if(!x){
            mxout[x] = -1;
        } else{
            int temp = *mxs[x].rbegin();
            mxs[p].erase(mxs[p].find(temp));
            mxout[x] = max(mxout[p],*mxs[p].rbegin());
            mxs[p].insert(temp);
        }
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
            }
        }
    };
    dfs2(dfs2,0,-1);
    int mx = -1;
    int ans;
    for(int i=0;i<n;i++){
        if(mxout[i]>a[i]){
            if(a[i]>mx){
                ans = i+1;
                mx = a[i];
            }
        }
    }
    cout << (mx==-1?0:ans) << "\n";
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
