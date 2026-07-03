#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t; // available on 64-bit targets

const int inf = 1e10;

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
    if(n==1){
        cout << 2 << "\n";
        return;
    } else if(n==2){
        cout << 1 << "\n";
        return;
    }
    int root;
    for(int i=0;i<n;i++){
        if((int)adj[i].size()>1){
            root = i;
        }
    }
    vector<vi> dp(n,vi(2));
    auto dfs = [&](auto self, int x, int p)->void{
        int sum = 0;
        int mx = -inf, mx2 = -inf;
        for(int y : adj[x]){
            if(y!=p){
                self(self,y,x);
                sum+=dp[y][0];
                int res = dp[y][0] - dp[y][1];
                if(res>mx){
                    mx2 = mx;
                    mx = res; 
                } else if(res==mx){
                    mx2 = mx;
                } else if(res>mx2){
                    mx2 = res;
                }
            }
        }
        dp[x][0] = sum + 2;
        dp[x][1] = sum;
        dp[x][0] = min(dp[x][0],sum-mx+1);
        dp[x][1] = min(dp[x][1],sum-mx+2);
    };
    dfs(dfs,root,-1);
    cout << dp[root][0] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}