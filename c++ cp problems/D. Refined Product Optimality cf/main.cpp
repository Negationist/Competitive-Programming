#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 998244353;

int binPowMod(int b, int p, int mod){
    int res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}

int modInv(int x, int mod){
    return binPowMod(x,mod-2,mod);
}


void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    auto c = a;
    auto d = b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res = 1;
    for(int i=0;i<n;i++){
        res*=min(a[i],b[i]);
        res%=mod;
    }
    cout << res << " ";
    while(q--){
        int o,x;
        cin >> o >> x;
        --x;
        if(o==1){
            int cur = c[x];
            ++c[x];
            int pos = upper_bound(a.begin(),a.end(),cur)-a.begin();
            --pos;
            res*=modInv(min(a[pos],b[pos]),mod);
            res%=mod;
            ++a[pos];
            res*=min(a[pos],b[pos]);
            res%=mod;
        } else{
            int cur = d[x];
            ++d[x];
            int pos = upper_bound(b.begin(),b.end(),cur)-b.begin();
            --pos;
            res*=modInv(min(a[pos],b[pos]),mod);
            res%=mod;
            ++b[pos];
            res*=min(a[pos],b[pos]);
            res%=mod;
        }
        cout << res << " ";
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
