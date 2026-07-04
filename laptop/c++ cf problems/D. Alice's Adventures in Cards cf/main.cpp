#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string peeps = "qkj";
    vector<vi> a(3,vi(n+1));
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    vector<pair<char,int>> sol(n+1,{'x',-1});
    int mn[3] = {n,n,n}; //of all the indexes such that they have a number than can reach n, this is the minimum
    for(int i=n-1;i>=1;i--){
        int win = -1;
        for(int j=0;j<3;j++){
            if(a[j][i]>a[j][mn[j]]) win = j;
        }
        if(win==-1) continue; //its impossible, else we can jump e.g 4->6->n with p(4) = 12, p(6) = 10, p(n) = 8
        sol[i] = {peeps[win],mn[win]};
        for(int j=0;j<3;j++){
            if(a[j][i]<a[j][mn[j]]) mn[j] = i;
        }
    }
    if(sol[1].second==-1){
        cout << "NO\n";
        return;
    }
    int cur = 1;
    vector<pair<char,int>> ans;
    cout << "YES\n";
    while(cur!=n){
        ans.pb(sol[cur]);
        cur = sol[cur].second;
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x.first << " " << x.second << "\n";
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
