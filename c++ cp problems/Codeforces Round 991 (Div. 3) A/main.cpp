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
    int n,m;
    cin >> n >> m;
    int ans = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(flag) continue;
        if(m>=s.size()){
            ans++;
            m-=s.size();
        } else{
            flag = true;
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
