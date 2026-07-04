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
    k--;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int big1 = n;
    int big2 = n;
    for(int i=0;i<n;i++){
        if(a[i]>a[k]){
            if(big1==n){
                big1 = i;
            } else{
                big2 = i;
                break;
            }
        }
    }
    int ans;
    if(k < big1){
        ans = big1-1;
    } else{
        int ans1 = big1-1;
        int ans2 = min(k,big2) - big1;
        if(big1==0) ans2--;
        ans = max(ans1,ans2);
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
