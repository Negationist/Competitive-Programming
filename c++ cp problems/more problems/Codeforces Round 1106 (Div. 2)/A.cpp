#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n,c;
    cin >> n >> c;
    vi a(n), b(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    bool flag = false;
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(a[i] < b[i]){
            flag = true;
        }
        sum-=b[i];
    }
    sort(all(a));
    sort(all(b));
    for(int i=0;i<n;i++){
        if(a[i] < b[i]){
            cout << "-1\n";
            return;
        }
    }
    int ans = 0;
    if(flag){
        ans+=c;
    }
    ans+=sum;
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
