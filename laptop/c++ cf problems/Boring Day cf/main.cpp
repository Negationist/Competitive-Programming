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
    int n,l,r,ans=0;
    cin >> n >> l >> r;
    vector<int> nums(n+1),pref(n+1);
    pref[0] = 0;
    for(int i=1;i<n+1;i++){
        int a;
        cin >> a;
        pref[i] = pref[i-1]+a;
    }
    int i=0,j=1;
    while(j<n+1){
        int sum = pref[j]-pref[i];
        if(sum>=l && sum<=r){
            ans++;
            i=j;
            j=i+1;
        } else if(sum<l){
            j++;
        } else if(sum>r){
            i++;
            j--;
            j = max(j,i+1);
        }
    }
    cout << ans << "\n";
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
