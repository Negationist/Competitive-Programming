#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
const int mod = 998244353;
void solve(){
    int n;
    cin >> n;
    priority_queue<ll> q;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        ll res = (ll)(i+1)*(n-i)*z;
        q.push(res);
    }
    vi b(n);
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    int j = 0;
    ll ans = 0;
    while(q.size()){
        int x = q.top();
        q.pop();
        x%=mod;
        ll res = x*b[j];
        ans = (ans+res)%mod;
        ++j;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
