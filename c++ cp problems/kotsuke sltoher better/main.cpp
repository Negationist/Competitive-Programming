#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int MOD = 1e9+7;

void solve(){
    int n,k;
    cin >> n >> k;
    n%=MOD;
    int a=1%k, b=1%k;
    int num = 1;
    while(a){
        num++;
        int z = (a+b)%k;
        a = b;
        b = z;
    }
    cout << (num*n)%MOD << "\n";
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
