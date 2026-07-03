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
    string s;
    cin >> s;
    int n = s.size();
    if(n==1){
        cout << -1 << "\n";
        return;
    }
    if(n==2){
        if(s[0]==s[1]){
            cout << s << "\n";
            return;
        } else{
            cout << -1 << "\n";
            return;
        }
    }
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cout << s[i] << s[i+1] << "\n";
            return;
        } else if(i<n-2 && s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]){
            cout << s[i] << s[i+1] << s[i+2] << "\n";
            return;
        }
    }
    cout << -1 << "\n";
    return;
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
