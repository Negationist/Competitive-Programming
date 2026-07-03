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
    string a,b;
    cin >> a >> b;
    int odd = 0, even = 0;
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            if(i&1){
                odd++;
            } else{
                even++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]=='0'){
            if(i&1){
                even--;
            } else{
                odd--;
            }
        }
    }
    if(odd<=0 && even<=0){
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
