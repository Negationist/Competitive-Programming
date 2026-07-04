#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
int mn = 1, mx = 1LL<<60;
uniform_int_distribution<int> dist(mn, mx);
map<int,int> m;

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(m[a[i]]==0) m[a[i]] = dist(rng);
        a[i] = m[a[i]];
    }
    vi pref(n+1); pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = a[i]^pref[i-1];
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        int sum = pref[r]^pref[l-1];
        if(sum==0){
            cout << "YES\n";
        } else cout << "NO\n";
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
