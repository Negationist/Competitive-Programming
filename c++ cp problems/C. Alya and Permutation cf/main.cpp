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
    int n;
    cin >> n;
    set<int> s;
    if(n==5){
        cout << 5 << "\n" << "2 1 3 4 5\n";
        return;
    } else if(n==6){
        cout << 7 << "\n" << "1 2 4 6 5 3\n";
        return;
    } else if (n==7){
        cout << 7 << "\n" << "2 4 5 1 3 6 7\n";
        return;
    } else if (n==8){
        cout << 15 << "\n" << "2 4 5 1 3 6 7 8 \n";
        return;
    }
    vi ans;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    int msb = 0;
    for(int i=0;i<63;i++){
        if(1LL<<i & n){
            msb = i;
        }
    }
    if(n%2==1){
        cout << n << "\n";
    } else{
        cout << (1LL<<(msb+1)) - 1 << "\n";
    }
    ans.pb(1LL<<msb);
    s.erase(1LL<<msb);
    ans.pb((1LL<<msb)-1);
    s.erase((1LL<<msb)-1);
    ans.pb((1LL<<msb)-2);
    s.erase((1LL<<msb)-2);
    ans.pb(1);
    s.erase(1);
    ans.pb((1LL<<(msb-1))+1);
    s.erase((1LL<<(msb-1))+1);
    if(n%2==1) s.erase(n);
    for(int x : s){
        ans.pb(x);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
    if(n%2==1) cout << n;
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
