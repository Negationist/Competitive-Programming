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
    int n,q;
    cin >> n >> q;
    int pref[n+1][n+1] = {};
    vector<string> s(n+1);
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i] = '+'+s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+(s[i][j]=='*');
        }
    }
    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        int res = pref[c][d];
        res+=pref[a][b];
        res-=pref[a][d];
        res-=pref[c][b];
        cout << res << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
