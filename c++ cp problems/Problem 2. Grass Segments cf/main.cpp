#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define tiii tuple<int,int,int>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<tiii> a(n);
    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        a[i] = {x,y,z};
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
