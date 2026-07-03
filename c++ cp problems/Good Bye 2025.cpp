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

int guess(int l, int r){
    cout << "? " << l+1 << " " << r+1 << "\n";
    cout.flush();
    int z; cin >> z;
    return z;
}

void solve(){
    int n;
    cin >> n;
    int tot = guess(0,n-1);
    auto max = [&](auto self, int l, int r, int sum){
        if(l==r) return guess(l,r);
        int lo = l, hi = r-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(guess(l,mid)>=sum/2){
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        if(lo-l <= r-(lo+1)){
            return self(self, l, lo, sum/2);
        } else{
            return self(self, lo+1, r, sum/2);
        }
    };
    int res = max(max, 0,n-1,tot);
    cout << res << "\n";
    cout.flush();
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