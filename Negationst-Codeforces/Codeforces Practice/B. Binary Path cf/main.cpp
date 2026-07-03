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
    vector<string> s;
    for(int i=0;i<2;i++){
        string z;
        cin >> z;
        s.pb(z);
    }
    string ans;
    int num = 1;
    pair<int,int> pos = {0,0};
    while(true){
        if(pos.second == n-1){
            ans.pb(s[0][n-1]);
            ans.pb(s[1][n-1]);
            break;
        }
        if(s[0][pos.second+1]=='1' && s[1][pos.second]=='0'){
            ans.pb(s[0][pos.second]);
            for(int i=pos.second;i<n;i++){
                ans.pb(s[1][i]);
            }
            break;
        } else{
            if(s[0][pos.second+1]==s[1][pos.second]){
                num++;
            } else{
                num=1;
            }
            ans.pb(s[0][pos.second]);
            pos.second++;
        }
    }
    cout << num << "\n" << ans << "\n";

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
