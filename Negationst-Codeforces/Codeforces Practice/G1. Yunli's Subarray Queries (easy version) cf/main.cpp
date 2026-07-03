#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,k,q;
    cin >> n >> k >> q;
    vi a(n);
    set<pii> s;
    map<int,int> cnt;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]+=(n-i);
    }
    for(int i=0;i<k;i++){
        int z = ++cnt[a[i]];
        s.erase({z-1,a[i]});
        s.insert({z,a[i]});
        ans[0] = k-(s.rbegin())->first;
    }
    for(int i=1;i+k-1<n;i++){
        int x = --cnt[a[i-1]];
        s.erase({x+1,a[i-1]});
        s.insert({x,a[i-1]});
        int y = ++cnt[a[i+k-1]];
        s.erase({y-1,a[i+k-1]});
        s.insert({y, a[i+k-1]});
        ans[i] = k-(s.rbegin())->first;
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        --a;
        cout << ans[a] << "\n";
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
