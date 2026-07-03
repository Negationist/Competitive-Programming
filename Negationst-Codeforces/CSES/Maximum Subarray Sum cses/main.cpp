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
    int a; cin >> a;
    int ans = a;
    int sum = a;
    int mn = min(a,0LL);
    for(int i=0;i<n-1;i++){
        int z;
        cin >> z;
        sum+=z;
        ans = max(ans,sum-mn);
        mn = min(mn,sum);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
