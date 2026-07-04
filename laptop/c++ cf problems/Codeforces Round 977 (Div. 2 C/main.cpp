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
    int n,m,q;
    cin >> n >> m >> q;
    int a[n], b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> c;
    set<int> s;
    map<int,int> pos;
    for(int i=0;i<m;i++){
        cin >> b[i];
        if(s.find(b[i]) == s.end()){
            s.insert(b[i]);
            c.pb(b[i]);
            pos[b[i]] = c.size();
        }
    }
    for(int i=0;i<q;i++){

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
