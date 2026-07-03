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
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int mx = -1;
    for(int i=1;i<=n;i++){
        if(i==0) mx = a[i];
        else{
            if(a[i]<=mx-2){
                cout << "NO\n";
                return;
            }
            mx = max(mx,a[i]);
        }
    }
    cout << "YES\n";
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
