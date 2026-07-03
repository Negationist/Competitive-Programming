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
    int n,x;
    cin >> n >> x;
    int ans = 1;
    set<int> d;
    d.insert(1);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        vector<int> cur;
        if(x%z==0){
            for(int a : d){
                cur.pb(a*z);
            }
        }
        for(int a : cur){
            if(x%a==0){
                d.insert(a);
            }
        }
        if(d.find(x)!=d.end()){
            ans++;
            d.clear();
            d.insert(1);
            d.insert(z);
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
