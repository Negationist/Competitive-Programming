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
    int n,m,k;
    cin >> n >> m >> k;
    int diff = k - (n+m-2);
    if(((n+m)%2 != k%2) || diff < 0){
        cout << "NO\n";
        return;
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
