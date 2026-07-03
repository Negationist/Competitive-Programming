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
   vi a(n);
   for(int i=0;i<n;i++){
        cin >> a[i];
   }
   int ans = LLONG_MAX;
   for(int i=0;i<n;i++){
        int cur = 0;
        for(int j=0;j<i;j++){
           if(a[j]>a[i]) cur = 1e7;
        }
        for(int j=i+1;j<n;j++){
           if(a[j]>a[i]) cur++;
        }
        ans = min(ans,cur+i);
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
