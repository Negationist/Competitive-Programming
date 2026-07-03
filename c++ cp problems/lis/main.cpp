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
    vector<int> ans;
    ans.pb(a[0]);
    for(int i=1;i<n;i++){
        int pos = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
        if(pos==ans.size()) ans.pb(a[i]);
        else ans[pos] = a[i];
    }
    cout << ans.size() << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
