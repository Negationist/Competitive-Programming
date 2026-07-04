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
    int n;
    cin >> n;
    vi ans;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=2;i<=50;i++){
        if(n%i!=0) continue;
        bool good = true;
        vi mx(i+1,-1);
        vi mn(i+1,1LL<<60);
        for(int j=1;j<=n;j++){
            mx[(i*j+n-1)/n] = max(a[j],mx[(i*j+n-1)/n]);
            mn[(i*j+n-1)/n] = min(a[j],mn[(i*j+n-1)/n]);
        }
        for(int j=2;j<=i;j++){
            if(mx[j-1]>=mn[j]){
                good = false;
            }
        }
        if(good){
            ans.pb(i);
        }
    }
    if(ans.size()){
        for(int x : ans){
            cout << x << " ";
        }
    } else{
        cout << -1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
