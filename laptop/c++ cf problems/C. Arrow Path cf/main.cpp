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
    vector<string> s(2);
    cin >> n;
    string test;
    for(int i=0;i<2;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            test.pb(s[1][i]);
        } else{
            test.pb(s[0][i]);
        }
    }
    for(int i=0;i<n-1;i++){
        if(test[i]=='<' && test[i+1]=='<'){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
