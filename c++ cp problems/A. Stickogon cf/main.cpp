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
    map<int,int> m;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        m[a]++;
    }
    for(auto it = m.begin();it!=m.end();it++){
        if(it->second<3) continue;
        while(true){
            m[it->first]-=3;
            if(m[it->first]>=0) ans++;
            else break;
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
