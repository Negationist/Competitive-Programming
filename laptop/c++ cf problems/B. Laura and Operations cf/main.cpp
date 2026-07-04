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
    int a,b,c;
    cin >> a >> b >> c;
    cout << ((b-c)%2==0) << " " << ((a-c)%2==0) << " " << ((b-a)%2==0) << "\n";
    return;
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
