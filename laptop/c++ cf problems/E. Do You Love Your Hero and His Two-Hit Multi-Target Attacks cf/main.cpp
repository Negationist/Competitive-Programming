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
    int k;
    cin >> k;
    int x = 0;
    int y = 0;
    int cur = 0;
    vii out;
    while(k>0){
        ++cur;
        int res = cur*(cur-1)/2;
        if(res<=k){
            out.pb({x,y});
            ++y;
        } else{
            --cur;
            res = cur*(cur-1)/2;
            ++x;
            ++y;
            k-=res;
            cur = 0;
        }
    }
    cout << out.size() << "\n";
    for(auto x : out){
        cout << x.ff << " " << x.ss << "\n";
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
