#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void dfs1(int cur, int p, vector<vi> &adj, int d, int &mx, int &best){
    if(d>=mx){
        mx = d;
        best = cur;
    }
    for(int x : adj[cur]){
        if(x==p) continue;
        dfs1(x,cur,adj, d+1, mx, best);
    }
}
void dfs2(int cur, int p, set<int> &s, vector<vi> &adj, int d, int &mx, int &best){
    s.erase(cur);
    if(d>=mx){
        mx = d;
        best = cur;
    }
    for(int x : adj[cur]){
        if(x==p) continue;
        dfs2(x, cur, s, adj, d+1, mx, best);
    }
}

void dfs3(int cur, int p, vector<vi> &adj, int d, vector<int> &distance, int push, vector<int> &tag){
    tag[cur] = push;
    distance[cur] = max(distance[cur],d);
    for(int x : adj[cur]){
        if(x==p) continue;
        dfs3(x,cur,adj,d+1,distance, push, tag);
    }
}

void solve(){
    int n,q;
    cin >> n >> q;
    vector<vi> adj(n);
    for(int i=0;i<n-3;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    pii t1,t2,t3;
    int d1 = -1,d2 = -1,d3=-1;
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(i);
    }
    vector<int> tag(n);
    dfs1(*s.begin(),-1,adj,0,d1,t1.ff);
    dfs2(t1.ff,-1,s,adj,0,d1,t1.ss);
    dfs1(*s.begin(),-1,adj,0,d2,t2.ff);
    dfs2(t2.ff,-1,s,adj,0,d2,t2.ss);
    dfs1(*s.begin(),-1,adj,0,d3,t3.ff);
    dfs2(t3.ff,-1,s,adj,0,d3,t3.ss);
    vector<int> distance(n,-1);
    dfs3(t1.ff, -1, adj, 0, distance,1,tag);
    dfs3(t1.ss, -1, adj, 0, distance,1,tag);
    dfs3(t2.ff, -1, adj, 0, distance,2,tag);
    dfs3(t2.ss, -1, adj, 0, distance,2,tag);
    dfs3(t3.ff, -1, adj, 0, distance,3,tag);
    dfs3(t3.ss, -1, adj, 0, distance,3,tag);
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        int res = distance[a]+distance[b];
        if(tag[a]!=1 && tag[b]!=1){
            res+=d1;
        }
        if(tag[a]!=2 && tag[b]!=2){
            res+=d2;
        }
        if(tag[a]!=3 && tag[b]!=3){
            res+=d3;
        }
        cout << res+3 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
