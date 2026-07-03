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
    int a,b;
    cin >> a >> b;
    queue<tuple<int,int,int>> q;
    q.push({0,a,b});
    while(true){
        auto [x,y,z] = q.front();
        if(!y && !z){
            cout << x << "\n";
            return;
        } else{
            q.push({x+1,y-gcd(y,z),z});
            q.push({x+1,y,z-gcd(y,z)});
        }
        q.pop();
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
