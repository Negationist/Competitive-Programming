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
    vi a(n+1);
    a[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n==1){
        cout << a[1]+k << "\n";
        return;
    }
    sort(a.begin(),a.end());
    int mn = a[1];
    bool done = false;
    for(int i=1;i<n;i++){
        i
    }
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
