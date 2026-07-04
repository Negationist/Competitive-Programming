#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

int get(vector<int> &a){
    int sum = 0;
    for(int x : a){
        sum+=x;
    }
    sum*=sum;
    for(int x : a){
        sum-=(x*x);
    }
    sum/=2;
    return sum;
}

void dfs(int cur, int p, int d, vector<vi> &adj, vector<vi> &depth, vi &lowness){
    lowness[cur] = d;
    depth[d].pb(cur);
    for(int x : adj[cur]){
        if(x!=p){
            dfs(x,cur,d+1,adj,depth,lowness);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vi val(n);
    vector<vi> depth(n);
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi lowness(n);
    dfs(0,-1,0,adj,depth,lowness);
    vector<map<int,int>> paths(n);
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        for(int x : depth[i]){
            if(adj[x].size()==1 && x!=0){
                paths[x][val[x]] = 1;
            } else{
                for(int y : adj[x]){
                    if(lowness[y]<lowness[x]) continue;
                    for(auto z : paths[y]){
                        paths[x][z.ff]+=z.ss;
                        if(z.ff==val[x]){
                            ans+=z.ss;
                        }
                    }
                }
                paths[x][val[x]] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        map<int,vector<int>> cnt;
        for(int x : adj[i]){
            if(lowness[x]<lowness[i]) continue;
            for(auto y : paths[x]){
                cnt[y.ff].pb(y.ss);
            }
        }
        for(auto x : cnt){
            if(x.ff == val[i]) continue;
            int res = get(x.ss);
            ans+=res;
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
