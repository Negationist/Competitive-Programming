#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define pb push_back
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 998244353;

void run_case() {
    ll n, k;
    cin >> n >> k;
    vector<pair<int, int>> events;
    for (int i=0; i<n; i++) {
        int u,v;
        cin >> u >> v;
        events.pb({u, -1});
        events.pb({v, 1});
    }
    sort(events.begin(),events.end());
    ll cnt = 0;
    ll ans = 1;
    for(auto [x,y]: events){
        if(y == 1){
            --cnt;
        } else{
            ans = (ans * (k - cnt));
            ans%=mod;
            ++cnt;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        run_case();
    }
}