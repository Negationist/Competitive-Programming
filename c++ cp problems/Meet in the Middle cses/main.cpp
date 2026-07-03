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
    int n,x;
    cin >> n >> x;
    int num = n/2;
    vi a(num),b(n-num);
    for(int i=0;i<num;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-num;i++){
        cin >> b[i];
    }
    vector<unordered_map<int,int>> m(2);
    int big = max(a.size(),b.size());
    int cnt = 1LL<<(big);
    int sum[cnt];
    sum[0] = 0;
    for(int i=1;i<(1LL<<a.size());i++){
        int msb = 63-__builtin_clzll(i);
        sum[i] = a[msb]+sum[i-(1LL<<msb)];
        m[0][sum[i]]++;
    }
    for(int i=1;i<(1LL<<b.size());i++){
        int msb = 63-__builtin_clzll(i);
        sum[i] = b[msb]+sum[i-(1LL<<msb)];
        m[1][sum[i]]++;
    }
    int ans = m[0][x]+m[1][x];
    for(auto z : m[0]){
        int num = x-z.ff;
        int res = z.ss*(m[1][num]);
        ans+=res;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
