#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

bool check(vector<vi> a, vector<vi> b, int c){
    int n = a.size();
    int m = a[0].size();
    vector<vi> adj(n+m); //first are columns then rows
    vector<int> color(n+m,0);
    vector<int> pending;
    auto dfs = [&](auto self, int cur)->bool{
        if(color[cur]) return false;
        color[cur] = 1;
        bool res = false;
        for(int x : adj[cur]){
            if(color[x]==0){
                res|=self(self,x);
            } else if(color[x]==1){
                res = true;
            }
        }
        color[cur] = 2;
        return res;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(((a[i][j]>>c)&1)!=((b[i][j]>>c)&1)){
                if((b[i][j]>>c)&1){
                    pending.pb(j);
                } else{
                    pending.pb(i+m);
                }
            }
            if((b[i][j]>>c)&1){
                adj[i+m].pb(j);
            } else{
                adj[j].pb(i+m);
            }
        }
    }
    for(int x : pending){
        if(dfs(dfs,x)){
            return false;
        }
    }
    return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vi> a(n,vi(m));
    auto b = a;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
        }
    }
    for(int i=0;i<30;i++){
        if(!(check(a,b,i))){
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
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
