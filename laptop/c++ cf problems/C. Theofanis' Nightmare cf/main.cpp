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
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int pref[n+1];
    pref[0] = 0;
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i]+a[i];
    }
    int mx = 0;
    int index = 0;
    for(int i=1;i<n+1;i++){
        if(pref[i]>mx
           )
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
