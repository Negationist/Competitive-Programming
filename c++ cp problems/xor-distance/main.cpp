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
    int a,b,r;
    cin >> a >> b >> r;
    if(a>b){
        swap(a,b);
    }
    int diff = 0;
    bool skip = true;
    for(int i=61;i>=0;i--){
        if((1LL<<i) & (a^b) && skip){
            skip = false;
            diff+=(1LL<<i);
            continue;
        }
        if((1LL<<i) & (a^b)){
            if(b & (1LL<<i)){
                if(r-(1LL<<i)>=0){
                    r-=(1LL<<i);
                    diff-=(1LL<<i);
                } else{
                    diff+=(1LL<<i);
                }
            } else{
                diff-=(1LL<<i);
            }
        }
    }
    cout << diff << "\n";
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
