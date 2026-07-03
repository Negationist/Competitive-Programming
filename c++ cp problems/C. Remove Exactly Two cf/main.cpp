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
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    multiset<int> cnt;
    for(int i=0;i<n;i++){
        cnt.insert(adj[i].size());
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int res = adj[i].size();
        cnt.erase(cnt.find(adj[i].size()));
        for(int x : adj[i]){
            cnt.erase(cnt.find(adj[x].size()));
            cnt.insert((adj[x].size()-1));
        }
        res+=*(cnt.rbegin());
        ans = max(ans,res);
        for(int x : adj[i]){
            cnt.erase(cnt.find(adj[x].size()-1));
            cnt.insert(adj[x].size());
        }
        cnt.insert(adj[i].size());
    }
    cout << max(ans-1,0LL) << '\n';
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
