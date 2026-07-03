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
    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    int k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    k = a[0];
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vi c;
    int j = 0;
    for(int i=0;i<m;i++){
        if(b[i]<=k){
            c.pb(0);
            continue;
        }
        while(j<n && a[j]<b[i]){
            j++;
        }
        c.pb(n-j);
    }
    sort(c.begin(),c.end());
    for(int i=1;i<=m;i++){
        int ans = 0;
        for(int j=i-1;j<m;j+=i){
            ans+=(c[j]+1);
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
