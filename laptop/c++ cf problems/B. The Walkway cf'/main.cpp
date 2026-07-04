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
    int n,m,d;
    cin  >> n >> m >> d;
    vi a;
    a.pb(1);
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        if(i==0 && z==1) continue;
        a.pb(z);
    }
    a.pb(n+1);
    int res = 0;
    int mx = -1, cnt = 0;
    for(int i=0;i<a.size();i++){
        int x = (s[i+1]-s[i]-1)/d+1;
        int y = (s[i+2]-s[i+1]-1)/d+1;
        int z = (s[i+2]-s[i]-1)/d+1;
        res+=(x);
        int cur = -(z-x-y);
        if(cur>mx){
            mx = cur;
            cnt = 0
        } else if(cur == mx){
            cnt++;
        }
    }
    cout << res-mx << " " << cnt << "\n";
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
