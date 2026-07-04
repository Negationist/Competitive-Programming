#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(k==1){
        if(a[0]>a.back()){
            int mx = -1;
            for(int i=1;i<n;i++){
                mx = max(mx,a[i]);
            }
            cout << mx+a[0] << "\n";
        } else{
            int mx = -1;
            for(int i=0;i<n-1;i++){
                mx = max(mx,a[i]);
            }
            cout << mx+a.back() << "\n";
        }
    } else{
        priority_queue<int> q;
        for(int x : a){
            q.push(x);
        }
        int ans = 0;
        for(int i=0;i<k+1;i++){
            ans+=q.top();
            q.pop();
        }
        cout << ans << "\n";
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
