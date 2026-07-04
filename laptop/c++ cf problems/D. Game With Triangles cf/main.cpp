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
    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vi c,d;
    int k = min((n+m)/3,min(n,m));
    cout << k << "\n";
    int l=0,r=n-1;
    while(l<r){
        c.pb(a[r]-a[l]);
        ++l;
        --r;
    }
    l=0; r=m-1;
    while(l<r){
        d.pb(b[r]-b[l]);
        ++l;
        --r;
    }
    vi f(c.size()+1),g(d.size()+1);
    f[0] = g[0] = 0;
    for(int i=1;i<=c.size();i++){
        f[i] = f[i-1]+c[i-1];
    }
    for(int i=1;i<=d.size();i++){
        g[i] = g[i-1]+d[i-1];
    }
    for(int i=1;i<=k;i++){
        int lo = max(0LL, 2*i-m);
        int hi = min(n-i,i);
        assert(lo>0 || i-lo>0);
        while(hi-lo>4){
            int m1 = lo+(hi-lo)/3;
            int m2 = hi-(hi-lo)/3;
            int res1 = f[m1]+g[i-m1];
            int res2 = f[m2]+g[i-m2];
            if(res1<res2){
                lo = m1;
            } else if(res1>=res2){
                hi = m2;
            }
        }
        int ans = 0;
        for(int j=lo;j<=hi;j++){
            int res = f[j]+g[i-j];
            ans = max(res,ans);
        }
        cout << ans << " ";
    }
    cout << "\n";
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
