#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int inf = 1e17;

void solve(){
    int n;
    cin >> n;
    vi a(n), l(n), r(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        l[i] = r[i] = i;
        while(l[i]-1>=0 && r[i]+1<n){
            --l[i];
            ++r[i];
        }
    }
    vector<vi> dp(n,vi(n,inf));
    for(int i=0;i<n;i++){
        dp[i][i] = 0;
    }
    for(int k=1;k<n;k++){
        vi visited(n,0);
        vector<vi> adj(n,vi(n,inf));
        for(int L=0;L<n;L++){
            int R = L+k;
            if(R>=n) continue;
            for(int i=0;i<n;i++){
                int maxl = max(L,l[i]), minr = min(R,r[i]);
                bool full = (maxl==L && minr==R);
                if(maxl>minr) continue;
                int r_p = maxl+(i-maxl)*2, l_p = minr+(i-minr)*2;
                if(!full){
                     if(maxl==L){ //overlap is on the left
                        dp[L][R] = min(dp[L][R],a[i]+max(dp[l_p][r_p],dp[minr+1][R]));
                    } else{
                        dp[L][R] = min(dp[L][R],a[i]+max(dp[l_p][r_p],dp[L][maxl-1]));
                    }  
                } else{
                    adj[l_p][L] = min(adj[l_p][L],a[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            int u = -1, mn = inf;
            for(int j=0;j<n;j++){
                if(j+k>=n) continue;
                if(!visited[j] && dp[j][j+k]<=mn){
                    u = j;
                    mn = dp[j][j+k];
                }
            }
            if(u==-1) break;
            visited[u] = true;
            for(int v=0;v<n;v++){
                if(v+k>=n) continue;
                dp[v][v+k] = min(dp[v][v+k], dp[u][u+k]+adj[u][v]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}