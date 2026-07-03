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
    vector<vector<bool>> a(4, vector<bool> (n, false));
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        a[i][0] = (s[0]=='B');
        a[i][1] = (s[0]=='G');
        a[i][2] = (s[0]=='R');
        a[i][3] = (s[0]=='Y');
        a[i][0] = (s[1]=='B');
        a[i][1] = (s[1]=='G');
        a[i][2] = (s[1]=='R');
        a[i][3] = (s[1]=='Y');
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;

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
