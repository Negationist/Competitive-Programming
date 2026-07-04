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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i-1]>1 && a[i]==1){
            cout << -1 << "\n";
            return;
        }
    }
    int x = 1,ans=0;
    for(int i=1;i<n;i++){
        long double j = x*log(a[i-1])/log(a[i]);
        int num = ceil(j);
        if(num<=1){
            x = 1;
            continue;
        }
        int next = 31-__builtin_clz(num);
        next+=(__builtin_popcount(num)>1);
        ans+=(next);
        x = 1LL<<next;
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
