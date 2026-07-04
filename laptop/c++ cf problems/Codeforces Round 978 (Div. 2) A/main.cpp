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
    int n,r;
    cin >> n >> r;
    int a[n];
    int ans = 0;
    int space = r;
    int alone = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
        ans+=(a[i]/2)*2;
        space-=(a[i]/2);
        if(a[i]%2==1){
            alone++;
        }
    }
    int open = space-(alone/2);
    if(alone%2==1){
        ans++;
        open--;
    }
    ans+=(open*2);
    cout << min(ans,sum) << "\n";
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
