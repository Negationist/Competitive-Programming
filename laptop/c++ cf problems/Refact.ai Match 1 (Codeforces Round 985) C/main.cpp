#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

bool check(vi a, int b){
    int n = a.size();
    vi f(n);
    vi g(n);
    int cur = 0;
    for(int i=0;i<n;i++){
        if(a[i]>cur){
            cur++;
        } else if(a[i]<cur){
            cur--;
        }
        f[i] = cur;
    }
    cur = b;
    for(int i=n-1;i>=0;i--){
        if(a[i]>=cur){
            cur--;
        } else{
            cur++;
        }
        g[i] = cur;
    }
    vi prefmx(n);
    vi suffmn(n);
    for(int i=0;i<n;i++){
        if(!i) prefmx[i] = f[i];
        else prefmx[i] = max(prefmx[i-1],f[i]);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1) suffmn[i] = g[i];
        else suffmn[i] = min(suffmn[i+1],g[i]);
    }
    suffmn.pb(b);
    for(int i=0;i<n-1;i++){
        if(prefmx[i]>=suffmn[i+2]){
            return true;
        }
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l = 1,r=n;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(check(a,mid)){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    cout << min(r,n-1) << "\n";
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
