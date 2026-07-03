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
    int l,r;
    cin >> l >> r;
    int msb = 63-__builtin_clzll(l^r);
    int a = r-(r%(1LL<<msb));
    int b = a-1;
    int c;
    for(int i=l;i<=r;i++){
        if(i!=b && i!=a){
            c = i;
            break;
        }
    }
    cout << a << " " << b << " " << c << "\n";
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
