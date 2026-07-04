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
    string a,b;
    cin >> a >> b;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        vii m;
        string match;
        getline(cin, match);
        stringstream sso(match);
        while(sso >> match){
            m.pb({match[0], match[2]});
        }
        cout << "num is " << m.size() << "\n";
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
