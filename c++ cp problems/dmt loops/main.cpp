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
    int fact[10];
    fact[0] = fact[1] = 1;
    for(int i=2;i<10;i++){
        fact[i] = fact[i-1]*i;
    }
    int ans = 1;
    for(int i=1;i<=3;i++){
        int res = 0;
        for(int j=0;j<=i;j++){
            res+=fact[j+1];
        }
        ans*=res;
    }
    cout << ans;
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
