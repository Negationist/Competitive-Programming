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
    int n,ans=0;
    cin >> n;
    int a[n+1] = {0};
    for(int i=1;i<n+1;i++){
        int z;
        cin >> z;
        a[z]++;
        if(a[z]==2){
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
