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
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=(s[i]=='('?1:-1);
        if(sum==0 && i!=n-1){
           cout << "YES\n";
           return;
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
