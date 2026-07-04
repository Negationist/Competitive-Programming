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
    vi g(100);
    g[0] = g[1] = 0;
    for(int i=2;i<100;i++){
        set<int> seen;
        for(int j=1;j<=i;j++){
            if(__gcd(i,j)!=1){
                seen.insert(g[i-j]);
            }
        }
        int inc = 0;
        while(seen.find(inc)!=seen.end()) inc++;
        g[i] = inc;
    }
    for(int i=0;i<100;i++){
        cout << "grundy " << i << " is " << g[i] << "\n";
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
