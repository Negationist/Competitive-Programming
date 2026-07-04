#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


void solve(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for(int b=1;b<=m;b++){
        for(int a=b;a<=n;a+=b){
            int x = a+b;
            int y = b*gcd(a,b);
            if(x%y==0){
                ans++;
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
