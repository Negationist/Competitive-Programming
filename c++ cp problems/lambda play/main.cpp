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
    auto gtr = [](int a,int b){
        return a>b;
    };
    cout << "enter: \n";
    int a,b;
    cin >> a >> b;
    if(gtr(a,b)){
        cout << "first is greater\n";
    } else{
        cout << "first is not greater\n";
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
