#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '+'+s;
    vi pref(n+1);
    pref[0] = 0;
    for (int i=1;i<=n;i++) {
        if (s[i]=='0') {
            pref[i] = pref[i-1]+1;
        } else {
            pref[i] = pref[i-1]-3;
        }
    }
    ordered_multiset<int> ms;
    map<int, int> cnt;
    ms.insert({0, 0});
    cnt[0] = 1;
    int ans = 0;
    for (int i=1;i<=n;i++) {
        int a = pref[i]+1;
        int b = pref[i]-2;
        int res = cnt[a];
        res += ms.order_of_key({b+1,0});
        cnt[pref[i]]++;
        ms.insert({pref[i],i});
        ans += res;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
