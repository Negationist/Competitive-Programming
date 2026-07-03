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
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
void solve(){
    int n,l,r,k;
    cin >> n >> l >> r >> k;
    if(n&1){
        cout << l << "\n";
    } else{
        int z = log2(l);
        int next = (1LL<<(z+1));
        if(next>r || n==2){
            cout << "-1\n";
        } else{
            if(k==n || k==n-1){
                cout << next << "\n";
            } else{
                cout << l << "\n";
            }
        }
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
