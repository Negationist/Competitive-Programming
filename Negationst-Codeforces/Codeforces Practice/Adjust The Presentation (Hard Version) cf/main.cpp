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
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    map<int,int> m1;
    for(int i=0;i<n-1;i++){
        m1[a[i]] = a[i+1];
    }
    set<int> s;
    s.insert(a[0]);
    int b[m];
    bool win = true;
    for(int i=0;i<m;i++){
        cin >> b[i];
        if(s.size()==n || !win) continue;
        if(s.find(b[i]) != s.end()){
            s.insert(m1[b[i]]);
        } else{
            win = false;
        }
    }
    if(win) cout << "YA\n";
    else cout << "TIDAK\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
