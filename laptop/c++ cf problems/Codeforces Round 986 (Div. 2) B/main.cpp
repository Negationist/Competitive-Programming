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
    int n,m,v;
    cin >> n >> m >> v;
    vi a(n+1),pref(n+1),l(n+1),r(n+2);
    a[0] = pref[0] = l[0] = r[n+1] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt+=a[i];
        if(cnt>=v){
            cnt = 0;
            l[i]++;
        }
        l[i]+=l[i-1];
    }
    cnt = 0;
    for(int i=n;i>=1;i--){
        cnt+=a[i];
        if(cnt>=v){
            cnt = 0;
            r[i]++;
        }
        r[i]+=r[i+1];
    }
    int ans = -1,j=1;
    for(int i=0;i<n;i++){
        bool flag = false;
        while(l[i]+r[j+1]>=m){
            j++;
            if(j==n+1){
                flag = true;
                break;
            }
        }
        if(l[i]+r[j]>=m){
            ans = max(ans, pref[j-1]-pref[i]);
        }
        if(flag) break;
    }
    cout << ans  << "\n";
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
