#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void dfs(int cur, int p, int d, vector<vi> &adj, vector<vi> &depths, vector<int> &lowness){
    depths[d].pb(cur);
    lowness[cur] = d;
    for(int x : adj[cur]){
        if(x!=p){
            dfs(x,cur,d+1,adj,depths,lowness);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    vector<vi> depths(n);
    vector<int> lowness(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1,0,adj,depths,lowness);
    vector<bool> good(n,false);
    for(int i=n-1;i>=0;i--){
        for(int x : depths[i]){
            bool able = true;
            for(int y : adj[x]){
                if(lowness[y]<lowness[x]) continue;
                if(good[y]==true) able = false;
            }
            if(able){
                good[x]=true;
            }
        }
    }
    if(good[0]==false){
        int cnt = 0;
        int last;
        for(int x : adj[0]){
            if(good[x]){
                cnt++;
                last = x;
            }
        }
        if(cnt==1){
            good[0] = true;
            if(adj[last].size()>1){
                good[last] = false;
            }
        }
    }
    vi ans;
    int sum = 0, tot = 0;
    for(int i=0;i<n;i++){
        if(good[i]){
            ans.pb(adj[i].size());
            tot++;
            sum+=(adj[i].size());
        } else{
            ans.pb(1);
            sum++;
        }
    }
    cout << tot << " " << sum << "\n";
    for(int x : ans){
        cout << x << " ";
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
