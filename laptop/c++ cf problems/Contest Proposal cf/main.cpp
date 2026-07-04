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
    int n,mx=0;
    cin >> n;
    bool possible = true;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int r = 0;
    for(int i=0;i<n;i++){
        if(!possible) {
            break;
        }
        while(a[i]>b[r]){
            r++;
            if(r>=n){
               possible = false;
               int remaining = (n-1) - i +1;
               mx = max(mx, remaining);
            }
        }
        if(possible) mx = max(mx, r-i);
    }
    cout << mx << endl;
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
