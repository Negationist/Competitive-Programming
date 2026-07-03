#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n-2;i++) cin >> a[i];
    for(int i=0;i+2<n-2;i++){
        if(a[i]==1 && a[i+1]==0 && a[i+2]==1){
            cout << "NO\n";
            return;
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
