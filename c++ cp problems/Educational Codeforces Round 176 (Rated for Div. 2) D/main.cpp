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
    int a,b;
    cin >> a >> b;
    string x,y;
    while(a){
        if(a&1){
            x.pb('1');
        } else{
            x.pb('0');
        }
        a>>=1;
    }
    while(b){
        if(b&1){
            y.pb('1');
        } else{
            y.pb('0');
        }
        b>>=1;
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int j = 0;
    int mn = min(x.size(),y.size());
    while(j<mn && x[j]==y[j]){
        ++j;
    }
    int c1 = x.size()-j;
    int c2 = y.size()-j;
    cout << x << "\n" << y << "\n";
    cout << c1 << "  " << c2 << "\n";
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
