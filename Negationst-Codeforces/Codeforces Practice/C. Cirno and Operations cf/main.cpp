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
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = -LLONG_MAX;
    vi global = a;
    while(global.size()>1){
        int res = 0;
        for(int x : global){
            res+=x;
        }
        ans = max(ans,res);
        auto temp = global;
        if(temp.back() < temp[0]){
            reverse(temp.begin(),temp.end());
        }
        vi cur;
        for(int i=1;i<temp.size();i++){
            int diff = temp[i]-temp[i-1];
            cur.pb(diff);
        }
        global = cur;
    }
    cout << max(ans,global[0]) << "\n";
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
