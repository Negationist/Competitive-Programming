#include <bits/stdc++.h>
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
    ll x,n,m;
    cin >> x >> n >> m;
    ll mn = x,mx = x;
    for(int i=0;i<n;i++){
        mx/=2;
        if(mx==0){
            break;
        }
    }
    for(int i=0;i<m;i++){
        mx = mx/2+(mx&1);
        if(mx<=1){
            break;
        }
    }
    for(int i=0;i<m;i++){
        mn = mn/2+(mn&1);
        if(mn<=1){
            break;
        }
    }
    for(int i=0;i<n;i++){
        mn/=2;
        if(mn==0){
            break;
        }
    }
    cout << mn << " " << mx << "\n";
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
