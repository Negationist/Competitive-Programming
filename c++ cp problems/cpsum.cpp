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
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t; // available on 64-bit targets

const int maxN = 1e6;

int sieve[maxN] = {};
 
void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
}

void solve(){
    compute();
    vi p;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            p.pb(i);
        }
    }
    int z = p.size();
    vi pref(z+1,0);
    for(int i=0;i<z;i++){
        pref[i+1] = pref[i]+p[i];
    }
    for(int i=1e3;;i--){
        for(int j=z;j-i>=0;j--){
            int res = pref[j] - pref[j-i];
            if(res<maxN && sieve[res] == res){
                cout << res << "\n";
                return;
            }
        }
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