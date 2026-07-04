#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int gcd(int x,int y){
    if(y%x==0) return x;
    return gcd(y%x,x);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int l,r,ans=0;
        cin >> l >> r;
        int n = r-l+1;
        if(n<3){
            cout << 0 << endl;
            continue;
        }
        if(l%2==1){
           ans++;
           n-=3;
        }
        ans+=(n/4);
        cout << ans << "\n";
    }
    return 0;
}
