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
const int mod = 998244353;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i=0;i<=29;i++){
        int base =  (1LL<<i);
        int sum_0 = 0, sum_1 = 0;
        int num_0 = 1, num_1 = 0;
        int p = 0;
        for(int j=0;j<n;j++){
            int cur = a[j]&(base), len = j+1;
            p^=cur;
            if(p){
                sum_1+=len;
                num_1++;
            } else{
                sum_0+=len;
                num_0++;
            }
            int res = (len*(len+1)/2)-(p?len*num_1-sum_1:len*num_0-sum_0);
            res%=mod;
            ans = (((res*base)%mod)+ans)%mod;
            //cout << j+1 << " on bit " << i << " has " << res << "\n";
        }
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
