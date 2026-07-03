#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 998244353;
const int maxN = 5e5+10;
vi fact(maxN);

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i)%mod;
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
    int n,c;
    cin >> n >> c;
    vi node;
    vii adj(n);
    vi val(n);
    for(int i=0;i<n;i++){
        int l,r,c;
        cin >> l >> r >> c;
        if(l!=-1) --l;
        if(r!=-1) --r;
        val[i] = c;
        adj[i].ff = l;
        adj[i].ss = r;
    }
    auto dfs = [&](auto self, int cur)->void{
        if(adj[cur].ff!=-1){
            self(self,adj[cur].ff);
        }
        node.pb(cur);
        if(adj[cur].ss!=-1){
            self(self,adj[cur].ss);
        }
    };
    dfs(dfs,0);
    auto starbar = [&](int n, int k) -> int {
        int res = 1;
        for(int i=k;i<=n+k-1;i++){
            res*=i;
            res%=mod;
        }
        res*=modInv(fact[n],mod);
        res%=mod;
        return res;
    };
    int lo = 1;
    int cnt = 0;
    int ans = 1;
    for(int i=0;i<n;i++){
        if(val[node[i]]!=-1){
            if(cnt>0){
                ans*=starbar(cnt,val[node[i]]-lo+1);
                ans%=mod;
            }
            lo = val[node[i]];
            cnt = 0;
        } else{
            ++cnt;
        }
    }
    if(cnt>0){
        ans*=starbar(cnt,c-lo+1);
        ans%=mod;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    compute();
    while(t--){
        solve();
    }
    return 0;
}
