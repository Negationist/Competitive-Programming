#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
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

ll MOD = 1e9+7;
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

const int maxN = 1e6; 
mi fact[maxN];

void compute(){
    fact[0] = 1;
    for(int i=1;i<maxN;i++){
        fact[i] = fact[i-1]*i;
    }
}

void solve(){ 
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vi color(n,2);
    mi ans = 1;
    bool good = true;
    auto dfs = [&](auto self, int x, int tag)->void{
        color[x] = tag;
        int decided = 0, big = 0, small = 0;
        for(int y : adj[x]){
            if(sz(adj[y])>1) ++big;
            else ++small;
            if(color[y]==2){
                self(self,y,!tag);
            } else{
                if(color[y]==color[x]){
                    good = false;
                }
                decided = 1;
            }
        }
        mi in = ans;
        if(big>2){
            good = 0;
        } else{
            if(decided){
                ans*=fact[small];
            } else{
                if(big==0){
                    ans*=fact[small];
                } else{
                    ans*=(2*fact[small]);
                }
            }
        }
        cout << ans/in << " for " << x << "!\n";
    };
    int num = 0;
    for(int i=0;i<n;i++){
        if(color[i]==2){
            ++num;
            dfs(dfs,i,0);
        }
    }
    cout << ans << "!\n";
    if(!good){
        cout << 0 << "\n";
    } else{
        cout << ans*fact[num]*mi(2) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}