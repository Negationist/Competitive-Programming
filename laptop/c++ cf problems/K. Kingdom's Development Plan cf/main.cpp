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

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--b].pb(--a); //go to a before b
    }
    for(int i=0;i<n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vi visited(n,0);
    vi pos(n);
    vi temp;
    auto dfs = [&](auto self, int x)->void{
        visited[x] = true;
        for(int y: adj[x]){
            if(!visited[y]){
                self(self,y);
            }
        }
        temp.pb(x);
        pos[x] = temp.size();
    };
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(dfs,i);
        }
    }
    bool win = true;
    for(int i=0;i<n;i++){
        for(int x : adj[i]){
            if(pos[x]>pos[i]){
                win = false;
            }
        }
    }
    if(win){
        for(int x : temp){
            cout << x+1 << " ";
        }
        cout << "\n";
    } else{
        cout << "IMPOSSIBLE\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
