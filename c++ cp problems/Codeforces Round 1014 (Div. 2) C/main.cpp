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
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    int sum = 0, num = 0;
    int mx = -1;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        sum+=z;
        if(z&1){
            ++num;
        }
        if(z>mx){
            mx = z;
        }
    }
    if(num==0 || num==n){
        cout << mx << "\n";
    } else{
        cout << sum-num+1 << "\n";
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
