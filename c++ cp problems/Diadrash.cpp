#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
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

int guess(int l, int r){
    cout  << "? " << l+1 << " " << r+1 << "\n";
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve(){
    int n,q;
    cin >> n >> q;
    vi right(n,-1);
    for(int i=0;i<q;i++){
        int l,r; cin >> l >> r;
        --l; --r;
        right[l] = max(right[l], r);
    }
    vii segs;
    int mx = -1;
    for(int i=0;i<n;i++){
        if(right[i]>mx){
            mx = right[i];
            segs.pb({i,right[i]});
        }
    }
    q = sz(segs);
    while(q>2){
        int m = q/2;
        //cout << segs[m].ff << " " << segs[m].ss << "!!\n";
        int x = guess(0, segs[m].ss), y = guess(segs[m].ff, n-1);
        vii temp;
        if(x<y){
            for(int i=m;i<q;i++){
                temp.pb(segs[i]);
            }
        } else{
            for(int i=0;i<=m;i++){
                temp.pb(segs[i]);
            }
        }
        segs = temp;
        q = sz(segs);
    }
    int ans = guess(segs[0].ff, segs[0].ss);
    if(q==2){
        ans = max(ans, guess(segs[1].ff, segs[1].ss));
    }
    cout << "! " << ans << "\n";
    cout.flush();
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