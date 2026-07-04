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
    int n,m,ans1=4,ans2=4;
    cin >> n >> m;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1==1 || x1==n){
        ans1--;
    }
    if(y1==1 || y1==m){
        ans1--;
    }
    if(x2==1 || x2==n){
        ans2--;
    }
    if(y2==1 || y2==m){
        ans2--;
    }
    cout << min(ans1,ans2) << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
