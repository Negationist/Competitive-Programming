#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 998244353;
void solve(){
    int n,k;
    cin >> n >> k;
    if(n<=63){
        if(k>(1LL<<(n-1))){
            cout << -1 << "\n";
            return;
        }
    }
    k--;
    vi a,b;
    for(int i=1;i<n;i++){
        int cur = n-i-1;
        if(cur>=40){
            a.pb(i);
            continue;
        }
        if(k&(1LL<<cur)){
            b.pb(i);
        } else{
            a.pb(i);
        }
    }
    for(int x : a){
        cout << x << " ";
    }
    reverse(b.begin(),b.end());
    cout << n << " ";
    for(int x : b){
        cout << x << " ";
    }
    cout << "\n";
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
