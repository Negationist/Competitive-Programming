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
    int a,b,r;
    cin >> a >> b >> r;
    int XOR = a^b;
    int ans = 0;
    int rsum = 0;
    bool found = false;
    for(int i=61;i>=0;i--){
        if(XOR & (1LL<<i) && !found){
            found = true;
            ans+=(1LL<<i);
        } else if(XOR & (1LL<<i)){
            ans-=(1LL<<i);
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
