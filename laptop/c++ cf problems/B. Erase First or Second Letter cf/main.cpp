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
    string s;
    cin >> n >> s;
    set<char> l;
    for(int i=0;i<n;i++){
        if(l.find(s[i])== l.end()){
            ans+=(n-i);
        }
        l.insert(s[i]);
    }
    cout << ans << endl;
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
