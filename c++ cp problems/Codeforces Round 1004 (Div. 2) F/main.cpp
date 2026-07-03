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
void solve(){
    int x,y;
    cin >> x >> y;
    int diff = y-x+9*100000;
    if(y<=x+1 && y!=x && diff%9==1){
        cout << "yes\n";
    } else{
        cout << "no\n";
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
