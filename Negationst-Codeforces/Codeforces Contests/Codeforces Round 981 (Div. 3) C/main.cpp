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
    for(int i=(n+1)/2;i>=0;i--){
        int stay = 0;
        if(i+1<n){
            stay+=(a[i]==a[i+1]);
        }
        if(i-1>=0){
            stay+=(a[i]==a[i-1]);
        }
        if(n-i-2>=0){
            stay+=(a[n-i-1]==a[n-i-2]);
        }
        if(n-i<n){
            stay+=(a[n-i-1]==a[n-i]);
        }
        int swp = 0;
        if(i+1<n){
            swp+=(a[n-i-1]==a[i+1]);
        }
        if(i-1>=0){
            swp+=(a[n-i-1]==a[i-1]);
        }
        if(n-i-2>=0){
            swp+=(a[i]==a[n-i-2]);
        }
        if(n-i<n){
            swp+=(a[i]==a[n-i]);
        }
        if(swp<stay){
            swap(a[i],a[n-i-1]);
        }
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            ans++;
        }
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
