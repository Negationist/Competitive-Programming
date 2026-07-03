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
    int x;
    cin >> x;
    multiset<int> a;
    a.insert(0);
    a.insert(0);
    a.insert(0);
    int inc = 0;
    while(true){
        int y = *a.begin();
        if(y==x) break;
        a.erase(a.find(y));
        int lo = *a.begin();
        a.insert(min(2*lo+1,x));
        ++inc;
    }
    cout << inc << "\n";
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
