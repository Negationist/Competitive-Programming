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
    int n;
    string s;
    cin >> n >> s;
    int x = 1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ++x;
        }
    }
    if(s[0]=='0'){
        if(x==1){
            cout << n << "\n";
        } else if(x==2 || x==3){
            cout << n+1 << "\n";
        } else{
            cout << n+x-3 << "\n";
        }
    } else{
        if(x<=3){
            cout << n+1 << "\n";
        } else{
            cout << n+x-2 << "\n";
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
