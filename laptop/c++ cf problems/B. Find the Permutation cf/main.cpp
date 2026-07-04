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

void solve(){
    int n;
    cin >> n;
    vector<set<int>> adj(n);
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(s[i][j]=='1'){
            adj[i].insert(j);
           }
        }
    }
    vi ans(n);
    iota(ans.begin(),ans.end(),0);
    sort(ans.begin(),ans.end(),
         [&](int i, int j){
                if(adj[i].find(j)!=adj[i].end()){
                    return i<j;
                } else{
                    return j<i;
                }
            }
         );
    for(int x : ans){
        cout << x+1 << " ";
    }
    cout << "\n";
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
