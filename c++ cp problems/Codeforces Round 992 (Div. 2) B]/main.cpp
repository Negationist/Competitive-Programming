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
    int n;
    cin >> n;
    if(n==1){
        cout << 1 << "\n";
        return;
    }
    int res = 2;
    int ans = 2;
    bool last = true;
    while(res<n){
        if(last){
            res*=2;
        } else{
            res++;
            ans++;
        }
        last = !last;
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
