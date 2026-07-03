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
    string s;
    cin >> s;
    int v = 0, h=0;
    for(int i=0;i<n;i++){
        v+=(s[i]=='N' ? 1 : 0);
        v-=(s[i]=='S' ? 1 : 0);
        h+=(s[i]=='E' ? 1 : 0);
        h-=(s[i]=='W' ? 1 : 0);
    }
    if(abs(v%2)==1 || abs(h%2)==1){
        cout << "NO\n";
        return;
    }
    v/=2; h/=2;
    pii fi = {0,0};
    string ans;
    int vcnt = 0, hcnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='N' || s[i]=='S'){
            vcnt++;
            if(fi.first!=v){
                ans.pb('R');
                fi.first+=(s[i]=='N' ? 1 : -1);
            } else{
                ans.pb('H');
            }
        } else{
            hcnt++;
            if(fi.second!=h){
                ans.pb('R');
                fi.second+=(s[i]=='E' ? 1 : -1);
            } else{
                ans.pb('H');
            }
        }
    }
    if(n==2){
        if(vcnt==2 && v==0){
            cout << "NO\n";
            return;
        }
        if(hcnt==2 && h==0){
            cout << "NO\n";
            return;
        }
    }
    if(h==0 && v==0){
        for(int i=1;i<n;i++){
            if((s[0]=='N' && s[i]=='S') || (s[0]=='S' && s[i]=='N')){
                ans[0] = 'R';
                ans[i] = 'R';
                break;
            }
            if((s[0]=='W' && s[i]=='E') || (s[0]=='E' && s[i]=='W')){
                ans[0] = 'R';
                ans[i] = 'R';
                break;
            }
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
