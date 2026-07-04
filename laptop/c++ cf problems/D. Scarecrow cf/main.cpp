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
long double eps = 1e-9;
using namespace std;

void solve(){
    int n,k,l;
    cin >> n >> k >>  l;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    pair<ld,ld> last = {a[0],k}; //time,position
    int ans = (a[0]+l-k)*2;
    for(int i=1;i<n;i++){
        ld x = last.ff, y = last.ss;
        ld far = a[i]+x, close = a[i]-x;
        if(far>=y && close<=y){
            last = {x,y+k};
        } else if(close>=y){
            ld diff = close-y;
            ld time = diff/2;
            last = {x+time, y+time+k};
        } else if(y-far<k){
            last = {x,far+k};
        }
        if(last.ss<l){
            int res = (last.ff+l-last.ss)*2;
            ans = min(ans,(int)res);
        } else{
            ans = min(ans,(int)(last.ff*2));
            break;
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
