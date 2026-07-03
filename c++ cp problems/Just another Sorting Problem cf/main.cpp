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
using u128 = unsigned __int128;
using i128 = __int128;
void solve(){
    int n; string s;
    cin >> n >> s;
    vi p(n+1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        if(p[i]!=i){
            ++cnt;
        }
    }
    if(s=="Alice"){
        if(cnt==2){
            cout << "Alice\n";
        } else{
            cout << "Bob\n";
        }
    } else{
        for(int i=1;i<n;i++){
            int res = cnt - (p[i]!=i) - (p[i+1] != i+1) + (p[i]!=i+1) + (p[i+1] != i);
            if(res>2){
                cout << "Bob\n";
                return;
            }
        }
        cout << "Alice\n";
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
