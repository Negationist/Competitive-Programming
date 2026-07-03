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
    int n,k;
    cin >> n >> k;
    if(k==1){
        if(n==1){
            cout << "1\n1\n";
        } else{
            cout << -1 << "\n";
        }
        return;
    }
    if(k==n){
        cout << -1 << "\n";
        return;
    }
    if((k-1)%2==1){
        cout << "3\n" << 1 << " " << k << " " << k+1 << "\n";
    } else{
        cout << "5\n" << 1 << " " << k-1 << " " << k << " " << k+1 << " " << k+2 << "\n";
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
