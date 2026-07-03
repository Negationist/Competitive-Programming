
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
    bool win = false;
    if(s[0]=='1' || s[n-1]=='1') win = true;
    for(int i=0;i<n-1;i++){
        if(s[i]=='1'&& s[i+1]=='1') win = true;
    }
    if(win){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
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
