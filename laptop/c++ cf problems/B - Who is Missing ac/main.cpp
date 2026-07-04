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
    int m,n;
    cin >> n >> m;
    set<int> s;
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        s.insert(z);
    }
    vi ans;
    for(int i=1;i<=n;i++){
        if(s.find(i)==s.end()){
            ans.pb(i);
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
