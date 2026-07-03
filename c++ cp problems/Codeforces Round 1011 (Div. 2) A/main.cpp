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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto x = s;
    reverse(x.begin(),x.end());
    if(!k){
        if(s<x){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    } else{
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                cout << "YES\n";
                return;
            }
        }
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
