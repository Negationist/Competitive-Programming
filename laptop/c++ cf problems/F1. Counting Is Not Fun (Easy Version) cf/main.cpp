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



const int maxN = 6e5+5;
const int mod = 998244353;
int fact[maxN];
int factInv[maxN];
int cata[maxN],cataInv[maxN];

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

int nCr(int n, int r){
    if(n<r) return 0;
    int res = fact[n]*factInv[n-r];
    res%=mod;
    res = res*factInv[r];
    res%=mod;
    return res;
}

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    factInv[maxN-1] = modInv(fact[maxN-1],mod);
    for(int i=maxN-2;i>=0;i--){
        factInv[i] = (factInv[i+1]*(i+1))%mod;
    }
    cata[0] = cata[1] = 1;
    cataInv[0] = cataInv[1] = 1;
    for(int i=2;i<maxN/2;i++){
        cata[i] = ((fact[2*i]*factInv[i+1])%mod*(factInv[i]))%mod;
        cataInv[i] = ((factInv[2*i]*fact[i+1])%mod*(fact[i]))%mod;
    }
}

struct dsu{
    vector<int> parent;
    vector<int> cnt;
    dsu(int n){
        parent.resize(n);
        cnt.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int _find(int i){
        if(i!=parent[i]){
            parent[i] = _find(parent[i]);
        }
        return parent[i];
    }
    bool unite(int a, int b){
        int x = _find(a);
        int y = _find(b);
        if(x==y) return false;
        if(cnt[x]<cnt[y]){
            swap(x,y);
        }
        parent[y] = x;
        cnt[x]+=cnt[y];
        return true;
    }
};

void solve(){
    int n;
    cin >> n;
    vi game(2*n),sze(n+1,1), hints(n);
    int inc = 1;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        game[--a] = inc++; game[--b] = 0;
        hints[n-1-i] = game[a];
    }
    vi par(n+1);
    stack<int> s;
    s.push(0);
    for(int i=0;i<2*n;i++){
        //cout << "here\n";
        if(game[i]){
            par[game[i]] = s.top();
            s.push(game[i]);
        } else{
            s.pop();
        }
    }
    dsu tree(n+1);
    int ans = 1;
    vi out;
    out.pb(1);
    for(int i=0;i<n;i++){
        int up = tree._find(par[hints[i]]);
        ans = (ans*cataInv[sze[tree._find(hints[i])]-1])%mod; //remove this size
        ans = (ans*cataInv[sze[up]-1])%mod; //remove up size
        int temp = sze[up]+sze[tree._find(hints[i])];
        tree.unite(hints[i],par[hints[i]]);
        sze[tree._find(hints[i])] = temp;
        ans = (ans*cata[temp-1])%mod; //merge
        out.pb(ans);
    }
    for(int i=out.size()-1;i>=0;i--){
        cout << out[i] << " \n"[i==0];
    }
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
