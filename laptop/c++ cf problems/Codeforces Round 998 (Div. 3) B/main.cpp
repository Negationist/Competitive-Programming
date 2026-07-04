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
    int n,m;
    cin >> n >> m;
    vector<vi> a(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        sort(a[i].begin(),a[i].end());
    }
    vi ans(n);
    iota(ans.begin(),ans.end(),0);
    sort(ans.begin(),ans.end(),
         [&](int i, int j){
                return a[i][0]<a[j][0];
            }
         );
    int last = -1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[ans[j]][i]<=last){
                cout << "-1\n";
                return;
            } else{
                last = a[ans[j]][i];
            }
        }
    }
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
