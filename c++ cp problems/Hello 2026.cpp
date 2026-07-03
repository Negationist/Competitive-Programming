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

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int MOD = 998244353;
struct mi {
    int v;
    explicit operator int() const { return v; }

    mi() : v(0) {}
    mi(long long _v) : v(int(_v % MOD)) { if (v < 0) v += MOD; }
};
mi &operator+=(mi &a, mi b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mi &operator-=(mi &a, mi b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi(1LL * a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    mi res = 1;
    while (p) { if (p & 1) res *= a; a *= a; p >>= 1; }
    return res;
}
mi inv(mi a) { assert(a.v); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
mi &operator/=(mi &a, mi b) { return a = a / b; }
inline bool operator==(mi a, mi b) { return a.v == b.v; }
inline bool operator!=(mi a, mi b) { return a.v != b.v; }
inline bool operator<(mi a, mi b)  { return a.v <  b.v; }
inline bool operator>(mi a, mi b)  { return a.v >  b.v; }
inline bool operator<=(mi a, mi b) { return a.v <= b.v; }
inline bool operator>=(mi a, mi b) { return a.v >= b.v; }
inline mi abs(mi a) { return (a.v < 0 ? mi(-a.v) : a); }
inline std::ostream& operator<<(std::ostream& os, const mi& x) { return os << x.v; }

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vi depth(n), isleaf(n, 1), par(n);
    auto dfs = [&](auto self, int x, int p, int d)->void {
        depth[x] = d;
        par[x] = p;
        for(int y : adj[x]){
            if(y!=p){
                isleaf[x] = 0;
                self(self, y, x, d+1);
            }
        }
    };
    dfs(dfs, 0, -1, 0);
    vi nodes;
    for(int i=0;i<n;i++){
        nodes.pb(i);
    }
    sort(all(nodes), [&](int a, int b){
        return (depth[a] > depth[b]);
    });
    mi ways[n]; //includes empty set
    for(int x : nodes){
        if(isleaf[x]){
            ways[x] = 2;
        } else{
            mi sum = 0, num = 0;
            for(int y : adj[x]){
                if(y!=par[x]){
                    sum+=ways[x];
                    num = num + 1;
                }
            }
            ways[x] = 2 * (sum - (num-1));
        }
    }
    mi dp[n][n];
    int ind[n][n];
    for(int x : nodes){
        for(int y : nodes){
            
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