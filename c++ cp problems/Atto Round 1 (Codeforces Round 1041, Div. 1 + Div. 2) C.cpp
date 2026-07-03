#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    ll n,k,delta = 1e11, ans = 0;
    cin >> n >> k;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vii events;
    for(int i=0;i<n;i++){
        ans+=(abs(a[i]-b[i]));
        events.pb({min(a[i],b[i]),-1}); //openings should come before closings
        events.pb({max(a[i],b[i]),1});
    }
    int cnt = 0;
    sort(all(events));
    for(auto [x,y] : events){
        cnt-=y;
        if(cnt>=2){
            cout << ans << "\n";
            return;
        }
    }
    vi mins(n),maxs(n);
    iota(all(mins),0);
    iota(all(maxs),0);
    sort(all(mins),[&](int i, int j){
        return min(a[i],b[i]) < min(a[j],b[j]);
    });
    sort(all(maxs),[&](int i, int j){
        return max(a[i],b[i]) < max(a[j],b[j]);
    });
    int i = 1, j = 0; //min ptr, max ptr
    ll min_num = -a[maxs[0]]-b[maxs[0]]-abs(a[maxs[0]]-b[maxs[0]]);
    while(i<n){
        //cout << "for " << a[mins[i]] << " " << b[mins[i]] << "\n";
        while(j+1<n && max(a[maxs[j+1]],b[maxs[j+1]])<min(a[mins[i]],b[mins[i]])){
            ++j;
            min_num = min(min_num,-a[maxs[j]]-b[maxs[j]]-abs(a[maxs[j]]-b[maxs[j]]));
        }
        //cout << "min_num is " << min_num << "\n";
        delta = min(delta,a[mins[i]]+b[mins[i]]-abs(a[mins[i]]-b[mins[i]])+min_num);
        ++i;
    }
    cout << ans+delta << "\n";
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