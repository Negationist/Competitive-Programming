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
    int n,l;
    cin >> n >> l;
    vector<pii> z(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        z[i] = {b,a};
    }
    sort(z.begin(), z.end());
    for(int i=0;i<n;i++){
        swap(z[i].first, z[i].second);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        multiset<int> m;
        int cur = 0;
        for(int j=i;j<n;j++){
            m.insert(z[j].first);
            cur+=(z[j].first);
            while(m.size() && z[j].second - z[i].second + cur > l){
                int mx = *m.rbegin();
                cur-=mx;
                m.erase(m.find(mx));
            }
            ans = max(ans, (int)m.size());
        }
    }
    cout << ans << "\n";
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
