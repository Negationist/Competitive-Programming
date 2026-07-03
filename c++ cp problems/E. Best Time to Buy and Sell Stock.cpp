#include <bits/stdc++.h>
#define int long long
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

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int inf = LLONG_MAX;

void solve(){
    int n;
    cin >> n;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    auto get = [&](vi a){
        n = (int)(a.size())-1;
        vi mx(n+1), mn(n+1);
        mn[1] = a[1];
        for(int i=2;i<=n;i++){
            mn[i] = min(mn[i-1], a[i]);
        }
        mx[n] = a[n];
        for(int i=n-1;i>=1;i--){
            mx[i] = max(mx[i+1], a[i]);
        }
        int idx = 1, mx_1 = -inf, mx_2 = -inf;
        for(int i=2;i<=n;i++){
            int val = a[i] - a[1];
            if(val >= mx_1){
                mx_2 = mx_1;
                mx_1 = val;
            } else if(val > mx_2){
                mx_2 = val;
            }
        }
        int mx_3 = -inf, mx_4 = -inf;
        for(int i=1;i<n;i++){
            int val = a[i] - a[n];
            if(val >= mx_3){
                mx_3 = mx_1;
                mx_4 = val;
            } else if(val > mx_4){
                mx_4 = val;
            }
        }
        if(mx_4 > mx_2){
            idx = n;
            mx_1 = mx_3;
            mx_2 = mx_4;
        }
        for(int i=2;i<n;i++){
            mx_3 = -inf, mx_4 = -inf;
            
        }
    };
    
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