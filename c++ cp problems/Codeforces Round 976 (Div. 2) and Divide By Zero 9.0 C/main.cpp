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
    int b,c,d,ans=0;
    cin >> b >> c >> d;
    for(int i=0;i<63;i++){
        if(1LL<<i & d){
            if((c & 1LL<<i) && !(b & 1LL<<i)){
                cout << -1 << "\n";
                return;
            }
            else if(!(c & 1LL<<i) && !(b & 1LL<<i)){
                ans+=(1LL<<i);
            }
        } else{
            if((c & 1LL<<i) && (b & 1LL<<i)){
                ans+=(1LL<<i);
            }
            else if(!(c & 1LL<<i) && (b & 1LL<<i)){
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << ans << "\n";
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
