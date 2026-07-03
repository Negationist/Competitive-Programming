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
    vector<string> s(2);
    cin >> n;
    for(int i=0;i<2;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        if(s[1][i]=='0') continue;
        if(s[0][i-1]=='1'){
            s[0][i-1]='2';
            ans++;
        }
        else if(s[0][i]=='0'){
            s[0][i]='2';
            ans++;
        }
        else if(s[0][i+1]=='1'){
            s[0][i+1]='2';
            ans++;
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
