#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        m[z]++;
    }
    bool g = false;
    for(auto x : m){
        if(m[x.ff-1]==0){
            g = false;
        }
        if(x.ss>=4){
            cout << "YES\n";
            return;
        } else if(x.ss==3 || x.ss==2){
            if(g){
                cout << "YES\n";
                return;
            } else{
                g = true;
            }
        }
    }
    cout << "NO\n";
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
