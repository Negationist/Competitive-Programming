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
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> val(t+1,vector<int>(n,0));
    val[0][s] = 1;
    vector<vi>adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int time = 1;
    while(t>time){
        for(int i=0;i<n;i++){
            for(int x : adj[i]){
                val[time][i]+=val[time-1][x];
            }
        }
        time++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=val[t-1][i]*adj[i].size();
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
