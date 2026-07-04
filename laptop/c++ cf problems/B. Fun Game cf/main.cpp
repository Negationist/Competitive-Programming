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
    string s1,s2;
    cin >> s1 >> s2;
    for(int i=0;i<n;i++){
        if(s1[i]=='1') break;
        if(s2[i]=='1'){
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
