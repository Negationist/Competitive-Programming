#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int MOD = 998244353;
const int MX = 1e6+5;
int sieve[MX] = {};

void compute(){
    for(int i=2;i<=sqrtl(MX);i++){
        if(sieve[i]) continue;
        for(int j=2*i;j<=MX;j+=i){
            sieve[j] = i;
        }
    }
}

void dfs(vector<int> &f, map<int,int> &tot, vector<int> &dp, int cnt, int cur, int prod, int i, bool good){
    if(prod!=1 && good){
        if(cnt%2==1){
            dp[i]+=tot[prod];
            dp[i]%=MOD;
        } else{
            dp[i]-=tot[prod];
            dp[i]+=MOD;
            dp[i]%=MOD;
        }
    }
    if(cur==f.size()) return;
    dfs(f,tot,dp,cnt+1,cur+1,prod*f[cur],i, true);
    dfs(f,tot,dp,cnt,cur+1,prod,i,false);
}
void dfs2(vector<int> &f, map<int,int> &tot, vector<int> &dp, int cnt, int cur, int prod, int i, bool good){
    if(prod!=1 && good){
        tot[prod]+=dp[i];
        tot[prod]%=MOD;
    }
    if(cur==f.size()) return;
    dfs2(f,tot,dp,cnt+1,cur+1,prod*f[cur],i,true);
    dfs2(f,tot,dp,cnt,cur+1,prod,i,false);
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi dp(n);
    dp[0] = 1;
    set<int> og;
    map<int,int> tot;
    while(sieve[a[0]]!=0){
        og.insert(sieve[a[0]]);
        a[0]/=sieve[a[0]];
    }
    og.insert(a[0]);
    vi ogreal;
    for(int x: og) ogreal.pb(x);
    dfs2(ogreal,tot,dp,0,0,1,0,0);
    for(int i=1;i<n;i++){
        set<int> f;
        while(sieve[a[i]]!=0){
            f.insert(sieve[a[i]]);
            a[i]/=sieve[a[i]];
        }
        f.insert(a[i]);
        vi real;
        for(int x : f){
            real.pb(x);
        }
        dfs(real,tot,dp,0,0,1,i,0);
        dfs2(real,tot,dp,0,0,1,i,0);
    }
    cout << dp[n-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
