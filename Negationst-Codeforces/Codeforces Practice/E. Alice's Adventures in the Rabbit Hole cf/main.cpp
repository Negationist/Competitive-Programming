#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int mod = 998244353;

int dfs(int cur, int p, int d, vii &ans, vector<vi> &adj){
    int mn = LLONG_MAX;
    bool isLeaf = true;
    for(int x : adj[cur]){
        if(x==p) continue;
        isLeaf = false;
        int res = dfs(x,cur,d+1,ans,adj);
        mn = min(mn,res);
    }
    if(isLeaf) mn = d;
    ans[cur].first = mn - d;
    ans[cur].second = mn;
    return mn;
}

int binPowMod(int b, int p, int mod){
    int res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}

int modInv(int x, int mod){
    return binPowMod(x,mod-2,mod);
}

void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vii ans(n);
    dfs(0,-1,0,ans,adj);
    int inc = 0;
    return;
    for(int i=0;i<n;i++){
        int x = ans[i].ff;
        int y = ans[i].ss;
        int res = x*modInv(y,mod);
        cout << res%mod << " ";
    }
    cout << "\n";
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
