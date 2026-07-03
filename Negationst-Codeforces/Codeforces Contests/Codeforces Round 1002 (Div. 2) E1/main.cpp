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
    int a[n][n],b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    map<int,vi> cnt;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int z;
            cin >> z;
            cnt[z].pb(n*i+j);
        }
    }
    map<int,int> cnt2;
    int ans = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt2[a[i][j]]++;
            if(cnt2[a[i][j]]>cnt[a[i][j]].size()){
                ans = max(ans,n*n-(n*i+j)+1);
            }
        }
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
