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
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(k==4){
        map<int,int>m;
        for(int i=0;i<n;i++){
            int cur = a[i]%k;
            m[cur]++;
        }
        if(m[0] || m[2]>=2){
            cout << 0;
        } else if(m[3] || m[2]){
            cout << 1;
        } else{
            cout << 2;
        }

    } else{
        int ans = LLONG_MAX;
        for(int i=0;i<n;i++){
            int cur = a[i]%k;
            ans = min(ans, (k-cur)%k);
        }
        cout << ans;
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
