#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
void solve(){
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    if(a>b){
        if((a^1)!=b){
            cout << -1 << "\n";
        } else{
            cout << y << "\n";
        }
        return;
    }
    int ans = 0;
    while(a<b){
        if((a^1)<a){
            ans+=x;
        } else{
            ans+=min(x,y);
        }
        a++;
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
