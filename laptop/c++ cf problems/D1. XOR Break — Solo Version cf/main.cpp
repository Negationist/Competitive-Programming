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
    int n,m;
    cin >> n >> m;
    set<int> a;
    set<int> b;
    for(int i=0;i<63;i++){
        if((1LL<<i)&n){
            a.insert(i);
        }
        if((1LL<<i)&m){
            b.insert(i);
        }
    }
    int msb = *(b.rbegin());
    if(a.find(msb)!=a.end()){
        cout << "1\n";
        cout << n << " " << m << "\n";
        return;
    }
    for(int i=0;i<=msb;i++){
        a.erase(i);
    }
    if(a.size()>1){
        cout << "2\n";
        int last = *(a.rbegin());
        int res = (1LL<<msb)+(1LL<<last);
        cout << n << " " << res << " " << m << "\n";
    } else{
        cout << -1 << "\n";
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
