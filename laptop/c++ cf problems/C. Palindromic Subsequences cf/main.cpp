#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n<=9){
        if(n==6){
            cout << "1 1 2 3 1 2\n";
        } else if(n==7){
            cout << "1 1 2 3 1 2 3\n";
        } else if(n==8){
            cout << "1 1 2 3 1 2 3 4\n";
        } else{
            cout << "7 3 3 7 5 3 7 7 3\n";
        }
        return;
    }
    int z = n/3;
    vi ends;
    vi mid;
    int inc = 0;
    for(int i=1;i<=z;i++){
        ends.pb(i);
        ++inc;
    }
    inc*=2;
    for(int i=z+1;inc<n;i++){
        mid.pb(i);
        ++inc;
    }
    for(int x : ends){
        cout << x << " ";
    }
    for(int x : mid){
        cout << x << " ";
    }
    for(int x : ends){
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
