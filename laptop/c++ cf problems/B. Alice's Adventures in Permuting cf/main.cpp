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
    int n,b,c;
    cin >> n >> b >> c;
    if(b==0){
        if(n<=c+2){
            if(c<=n-1){
                cout << n-1 << "\n";
            } else{
                cout << n << "\n";
            }
        } else{
            cout << -1 << "\n";
        }
    } else{
        if(c>n-1){
            cout << n << "\n";
        } else{
            int mx = (2e18-c)/b;
            int l=1,r=mx;
            while(l<=r){
                int mid = l+(r-l)/2;
                int res = b*(mid-1)+c;
                if(res<=n-1){
                    l = mid+1;
                } else{
                    r = mid-1;
                }
            }
            cout << n-r << "\n";
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
