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
    int n,m,k;
    cin >> n >> m >> k;
    vi a(m);
    vector<int> adj(n);
    for(int i=0;i<m;i++){
        cin >> a[i];
        for(int j=0;j<i;i++){
            adj[i].pb(a[j]);
        }
    }
    for(int i=0;i<k;i++){

    }
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
