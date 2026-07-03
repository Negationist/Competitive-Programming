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
const int maxN = 1e5+5;
int sieve[maxN] = {};
vector<vi> adj(maxN+5,vi());
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


void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        for(int j=i;j<maxN;j+=i){
            sieve[j] = i;
            adj[j].pb(i);
        }
    }
}

int nCr(int n, int r){
    if(n<r) return 0;
    int ans = 1;
    for(int i=1;i<=r;i++){
        ans*=(n-r+i);
        ans%=mod;
        ans*=modInv(i,mod);
        ans%=mod;
    }
    return ans;
}

void solve(){
    int k,n;
    cin >> k >> n;
    int dp[k+1][18] = {};
    for(int i=2;i<=k;i++){
        dp[i][1] = 1;
    }
    for(int i=1;i<=k;i++){
        if(i==1) continue;
        for(int j=1;j<=17;j++){
            for(int x : adj[i]){
                dp[i][j]+=dp[i/x][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    for(int i=1;i<=k;i++){
        if(i==1){
            cout << n << " ";
            continue;
        }
        int ans = 0;
        for(int j=0;j<18;j++){
            int res = dp[i][j]*nCr(n+1,j+1);
            ans = (ans+res)%mod;
        }
        cout << ans << " ";
    }
    cout << "\n";
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
