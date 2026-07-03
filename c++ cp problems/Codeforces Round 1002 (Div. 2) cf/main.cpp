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
    int n,s1,s2;
    cin >> n >> s1 >> s2;
    vector<vi> adj1(n),adj2(n);
    int m1;
    cin >> m1;
    for(int i=0;i<m1;i++){
        int a,b;
        cin >> a >> b;
        adj1[--a].pb(--b);
        adj1[b].pb(a);
    }
    int m2;
    cin >> m2;
    for(int i=0;i<m2;i++){
        int a,b;
        cin >> a >> b;
        adj2[--a].pb(--b);
        adj2[b].pb(a);
    }
    set<pii> p1;
    for(int i=0;i<n;i++){
        for(int x : adj1[i]){
            p1.insert({min(i,x),max(i,x)});
        }
    }
    set<pii> p2;
    for(int i=0;i<n;i++){
        for(int x : adj2[i]){
            pii cur = {min(i,x),max(i,x)};
            if(p1.find(cur)!=p1.end()){
                p2.insert(cur);
            }
        }
    }
    set<int> good;
    for(auto x : p2){
        good.insert(x.ff);
        good.insert(x.ss);
    }
    vector<vi> dp1(n,vi(2,inf));
    vector<vi> dp2(n,vi(2,inf)); //minimum even and odd lengths
    dp1[s1][0] = 0;
    dp2[s2][0] = 0;
    for(int i=0;i<3000;i++){
        vector<vi> ndp1(n,vi(2,inf));
        vector<vi> ndp2(n,vi(2,inf));
        for(int j=0;j<n;j++){
            for(int x : adj1[j]){
                ndp1[i][0] = min(dp[i][0],min(ndp[i][0],dp[x][1]+1));
            }
        }
        dp = move(ndp1);
        dp2 = move(ndp2);
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
