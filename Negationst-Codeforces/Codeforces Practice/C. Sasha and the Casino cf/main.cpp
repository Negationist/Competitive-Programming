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
    int k,x,a;
    cin >> k >> x >> a;
    a--;
    int loss = 1;
    for(int i=2;i<=x+1;i++){
        int bet = loss/(k-1)+1;
        if(a>=bet){
            a-=bet;
            loss+=bet;
        } else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
