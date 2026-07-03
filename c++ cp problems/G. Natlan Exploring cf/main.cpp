#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int inf = 1LL<<60;

void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        int z;
        cin >> z;
        a[z] = i;
    }
    vector<int> dp(n+1, inf);
    map<int,set<int>> pos;
    for(int i=1;i<=n;i++){
        pos[i].insert(inf);
    }
    vi b(m+1);
    for(int i=1;i<=m;i++){
        int z;
        cin >> z;
        b[i] = z;
        int x = a[z];
        dp[x] = min(dp[x],i);
        pos[x].insert(i);
    }
    set<pii> bad;
    for(int i=1;i<=n;i++){
        if(i<n){
            if(dp[i]>dp[i+1]){
                bad.insert({i,i+1});
            }
        }
    }
    if(!bad.size()){
        cout << "ya\n";
    } else cout << "TIDAK\n";
    while(q--){
        int x,y;
        cin >> x >> y;
        int prev = a[b[x]];
        pos[prev].erase(x);
        dp[prev] = *pos[prev].begin();
        int cur = a[y];
        pos[cur].insert(x);
        dp[cur] = *pos[cur].begin();
        b[x] = y;
        if(cur<n){
            if(dp[cur]>dp[cur+1]){
                bad.insert({cur,cur+1});
            } else bad.erase({cur,cur+1});
        }
        if(cur>1){
            if(dp[cur-1]>dp[cur]){
                bad.insert({cur-1,cur});
            } else bad.erase({cur-1,cur});
        }
        if(prev<n){
            if(dp[prev]>dp[prev+1]){
                bad.insert({prev,prev+1});
            } else bad.erase({prev,prev+1});
        }
        if(prev>1){
            if(dp[prev-1]>dp[prev]){
                bad.insert({prev-1,prev});
            } else bad.erase({prev-1,prev});
        }
        if(!bad.size()){
            cout << "ya\n";
        } else cout << "TIDAK\n";
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
