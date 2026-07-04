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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    bool WU,WD,WL,WR,BU,BD,BL,BR;
    WU = WD = WL = WR = BU = BD = BL = BR = false;
    for(int i=0;i<m;i++){
        if(a[0][i]=='W') WU = true;
        else BU = true;
    }
    for(int i=0;i<m;i++){
        if(a[n-1][i]=='W') WD = true;
        else BD = true;
    }
    for(int i=0;i<n;i++){
        if(a[i][0]=='W') WL = true;
        else BL = true;
    }
    for(int i=0;i<n;i++){
        if(a[i][m-1]=='W') WR = true;
        else BR = true;
    }
    if(WU && WD && WL && WR){
        cout << "Yes\n";
    } else if(BU && BD && BL && BR){
        cout << "Yes\n";
    } else{
        cout << "No\n";
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
