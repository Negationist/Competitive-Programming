#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vii depth;

void dfs(int cur, int dis){
    depth[cur].first = dis;
    depth[cur].second = dis;
    visited[cur] = true;
    for(int x : adj[cur]){
        if(visited[x]==false){
            dfs(x,dis+1);
            depth[cur].second = max(depth[cur].second, depth[x].second);
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        adj.assign(n,vector<int>(0));
        visited.assign(n,false);
        depth.resize(n);
        for(int i=0;i<n-1;i++){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(0,0);
        int intervals[n+1] = {};
        for(auto it : depth){
            intervals[it.first]++;
            if(it.second + 1 <n+1){
                intervals[it.second+1]--;
            }
        }
        int sum = 0;
        int mx = -1;
        int fD;
        for(int i=0;i<=n;i++){
            sum+=intervals[i];
            if(sum>mx){
                fD = i;
                mx = sum;
            }
        }
        int ops = 0;
        for(auto it : depth){
            if(it.first<=fD && it.second>=fD){
                continue;
            }
            ops++;
        }
        cout << ops << endl;
    }
    return 0;
}
