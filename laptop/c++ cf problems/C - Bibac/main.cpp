#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi p(n+1);
    vi q(n+1);
    vi pos(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    for(int i=1;i<=n;i++){
        cin >> q[i];
        pos[q[i]] = i;
    }
    for(int i=1;i<=n;i++){
        cout << q[p[pos[i]]] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
