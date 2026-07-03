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
    int ans = 0;
    int cnt = 1;
    int mid;
    int temp = n;
    if(n%2==1){
        mid = (1+n)/2;
    } else{
        mid = (1+n);
    }
    while(temp>=k){
        if(temp%2==1) ans+=(mid*cnt);
        cnt*=2;
        temp/=2;
    }
    if(n%2==0){
        ans/=2;
    }
    cout << ans << "\n";
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
