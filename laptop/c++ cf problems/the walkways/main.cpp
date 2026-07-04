#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void debug(int z){
    cout << z << "\n";
}

void solve(){
    int n,m,d;
    cin  >> n >> m >> d;
    vi s;
    s.pb(1);
    bool cancer = false;
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        if(i==0 && z==1){
            cancer = true;
            continue;
        }
        s.pb(z);
    }
    s.pb(n+1);
    int res = 0;
    int mx = -1, cnt = 0;
    for(int i=0;i<s.size()-2;i++){
        int x = (s[i+1]-s[i]-1)/d+1;
        int y = (s[i+2]-s[i+1]-1)/d+1;
        int z = (s[i+2]-s[i]-1)/d+1;
        res+=(x);
        int cur = -(z-x-y);
        if(cur>mx){
            mx = cur;
            cnt = 1;
        } else if(cur == mx){
            cnt++;
        }
        if(i==s.size()-3){
            res+=y;
        }
    }
    cnt+=(mx==0 && cancer) ;
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
