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
    int q;
    cin >> s >> q;
    int n = s.size();
    set<int> w;
    for(int i=0;i<n-3;i++){
        if(s.substr(i,4)=="1100"){
            w.insert(i);
        }
    }
    while(q--){
        int p,v;
        cin >> p >> v;
        s[p-1] = v+'0';
        for(int i=max(0LL,p-6);i<min(p+6,n-3);i++){
            if(s.substr(i,4)=="1100"){
                w.insert(i);
            } else{
                w.erase(i);
            }
        }
        if(w.size()){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
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
