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
    cout << "YES\n";
    int n;
    cin >> n;
    vi a(n+1);
    set<int> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        s.insert(i);
    }
    vii out;
    for(int i=n-1;i>=1;i--){
        map<int,int> seen;
        int cur;
        for(int x : s){
            if(!seen[a[x]%i]){
                seen[a[x]%i] = x;
            } else{
                out.pb({seen[a[x]%i],x});
                cur = x;
                break;
            }
        }
        s.erase(cur);
    }
    for(int i=out.size()-1;i>=0;i--){
        cout << out[i].ff << " " << out[i].ss << "\n";
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
