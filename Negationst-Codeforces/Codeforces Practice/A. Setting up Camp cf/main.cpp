//time : 2:00
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
    int a,b,c;
    cin >> a >> b >> c;
    if(b%3==0){
        cout << a+b/3+(c+2)/3 << "\n";
        return;
    } else if(b%3==1){
        if(c>=2){
            cout << a+(b+c+2)/3 << "\n";
            return;
        }
    } else{
        if(c!=0){
            cout << a+(b+c+2)/3 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
