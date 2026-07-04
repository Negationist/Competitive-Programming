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
    int n,k;
    cin >> n >> k;
    vi a(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ++cnt[a[i]];
    }
    int tot = n;
    int good = 0;
    for(auto x : cnt){
        int other = cnt[k-x.ff];
        int mx = min(x.ss,other);
        good+=mx;
    }
    cout << good/2 << "\n";
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
