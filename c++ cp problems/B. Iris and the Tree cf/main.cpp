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
    int n,w;
    cin >> n >> w;
    map<int, map<int,int>> adj;
    int p[n];
    for(int i=1;i<n;i++){
        int z;
        cin >> z;
        z--;
        p[i] = z;
        adj[z][i] = -1;
        adj[i][z] = -1;
    }
    int posV = w;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        x--;
        adj[x][p[x]] = y;
        adj[p[x]][x] = y;
    }
    posV-=y;
    for(int i=0;i<n;i++){
        int first = i;
        int sec = (i+1)%n;
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
