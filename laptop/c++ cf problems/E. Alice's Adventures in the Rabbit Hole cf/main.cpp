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

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int dfs(int cur, int p, int d, vector<vi> &adj, vi &cD){
    int mn = LLONG_MAX;
    bool isLeaf = true;
    for(int x : adj[cur]){
        if(x==p) continue;
        isLeaf = false;
        int res = dfs(x,cur,d+1,adj,cD);
        mn = min(mn, res);
    }
    if(isLeaf) mn = d;
    cD[cur] = mn-d;
    return mn;
}

void dfs2(int cur, int p, vii &chance, vi &cD, vector<vi> &adj){
    if(cur){
        int x = chance[p].ff*cD[cur] %mod;
        int y = chance[p].ss*(cD[cur]+1) % mod;
        int z = gcd(x,y);
        x/=z;
        y/=z;
        chance[cur] = {x,y};
    }
    for(int x : adj[cur]){
        if(x==p) continue;
        dfs2(x,cur,chance, cD, adj);
    }
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
    vector<int> cD(n);
    vii chance(n);
    chance[0] = {1,1};
    dfs(0,-1,0,adj,cD);
    dfs2(0,-1,chance,cD,adj);
    for(int i=0;i<n;i++){
        int res = chance[i].ff*modInv(chance[i].ss, mod);
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
