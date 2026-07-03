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
    vi ans;
    if(n==1 || n==3){
        cout << -1;
    } else{
        if(n%2==0){
            for(int i=0;i<n;i++){
                if(i<2) ans.pb(6);
                else ans.pb(3);
            }
        } else{
            ans.pb(36366);
            for(int i=0;i<n-5;i++){
                ans.pb(3);
            }
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i];
    }
    cout << "\n";
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
