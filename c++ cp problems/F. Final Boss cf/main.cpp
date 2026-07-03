#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int MOD = 1e9+7;

void solve(){
    string s;
    cin >> s;
    int ans = 0;
    int n=s.size();
    vi pref(n+1,0);
    vector<vi> z(2*n+2);
    z[n].pb(0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + (s[i]=='1' ? 1 : -1);
        z[pref[i+1]+n].pb(i+1);
    }
    for(int i=0;i<2*n;i++){
        int cnt = z[i].size();
        if(cnt<2) continue;
        int prefz[cnt] = {};
        for(int j=1;j<cnt;j++){
            prefz[j] = prefz[j-1] + (n - z[i][j]+1);
        }
        for(int j=0;j<cnt-1;j++){
            ans+=(((z[i][j]+1)%MOD)*((prefz[cnt-1] - prefz[j])%MOD))%MOD;
            ans%=MOD;
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
