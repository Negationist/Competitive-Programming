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
    vi a(n);
    int tot = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        tot+=a[i];
    }
    if(n<=2){
        cout << -1 << "\n";
        return;
    }
    sort(a.begin(),a.end());
    int mx = a.back();
    int next = a[n/2];
    int thres = next*2*n+1;
    cout << max(0LL,thres-tot) << "\n";
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
