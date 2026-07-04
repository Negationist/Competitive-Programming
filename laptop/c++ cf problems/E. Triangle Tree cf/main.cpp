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
const int maxN = 3e5+5;
void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vi sze(n),depth(n);
    vi depths(n+5,0);
    depth[0] = 1;
    auto dfs = [&](auto self, int cur, int p)->void{
        if(cur){
            depth[cur] = depth[p]+1;
        }
        sze[cur] = 1;
        for(int x : adj[cur]){
            if(x!=p){
                self(self,x,cur);
                sze[cur]+=sze[x];
            }
        }
        ++depths[depth[cur]];
    };
    dfs(dfs,0,-1);
    int pref[n+5];
    pref[0] = 0;
    for(int i=1;i<=n+4;i++){
        pref[i] = pref[i-1]+depths[i];
    }
    int tot = 0;
    for(int i=0;i<n;i++){
        int res = depth[i]*(n-sze[i]-(depth[i]-1));
        //cout << "there are " << (n-sze[i]-(depth[i]-1)) << "not sub or ancestor " << " for " << i << "\n";
        tot+=(n-sze[i]-(depth[i]-1));
        ans+=res;
    }
    ans-=(tot/2);
    //cout << ans << "!\n";
    auto dfs2 = [&](auto self, int cur, int p)->void{
        vi temp;
        for(int x : adj[cur]){
            if(x!=p){
                self(self,x,cur);
                temp.pb(sze[x]);
            }
        }
        int sum = 0, sqrsum = 0;
        for(int x : temp){
            sum+=x;
            sqrsum+=(x*x);
        }
        int res1 = ((sum*sum)-sqrsum)/2;
        int res2 = -2*res1*depth[cur];
        ans+=res2;
    };
    dfs2(dfs2,0,-1);
    //cout << ans << "!\n";
    int ans2 = 0;
    for(int i=0;i<n;i++){
        int res1 = (pref[depth[i]-1]-(depth[i]-1))*depth[i];
        int res2 = ((pref[n+4]-pref[depth[i]])-(sze[i]-1))*depth[i];
        //cout << i << "is upper for " << (pref[depth[i]-1]-(depth[i]-1)) << "\n";
        //cout << i << "is lower for " << ((pref[n+4]-pref[depth[i]])-(sze[i]-1)) << "\n";
        /*cout << pref[n+4] << "!\n";
        cout << pref[depth[i]] << "!\n";
        cout << (sze[i]-1) << "!\n";*/
        //cout << res1 << "\n";
        //cout << res2 << "\n";
        ans-=res1;
        ans+=res2;
    }
    cout << ans << "\n";
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
