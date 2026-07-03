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
void solve(){
    int n;
    cin >> n;
    vi ans(n+1,-1);
    bool flag = false;
    for(int i=1;i<n;i++){
        if(i==1 && n&1){
            ans[1] = n;
            flag = true;
            break;
        }
        if(n%i==i-1 && n%(i+1)==i){
            ans[i] = n;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << -1 << "\n";
    } else{
        int inc = 1;
        for(int i=1;i<=n;i++){
            if(ans[i]==-1){
                cout << inc++ << " ";
            } else{
                cout << n << " ";
            }
        }
        cout << "\n";
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
