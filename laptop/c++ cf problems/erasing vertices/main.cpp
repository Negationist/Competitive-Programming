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
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j]=='1'){
                adj[j].pb(i);
            }
        }
    }
    long double ans = 0;
    long double cnt;
    vector<int> visited(n,false);
    auto dfs = [&](auto self, int cur)->void{
        ++cnt;
        visited[cur] = true;
        for(int x : adj[cur]){
            if(visited[x]==false){
                self(self, x);
            }
        }
    };
    for(int i=0;i<n;i++){
        visited.assign(n,false);
        cnt = 0;
        dfs(dfs,i);
        ans+=(1/cnt);
    }
    cout << fixed << setprecision(15) << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
