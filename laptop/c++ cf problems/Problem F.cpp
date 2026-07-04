#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int w,h,x,y,n;
    cin >> w >> h >> x >> y >> n;
    map<int, vi> x_b, y_b;
    map<pii, int> visited;
    queue<pii> q;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        x_b[a].pb(b);
        y_b[b].pb(a);
    }
    for(auto l : x_b){
        sort(l.ss.begin(),l.ss.end());
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