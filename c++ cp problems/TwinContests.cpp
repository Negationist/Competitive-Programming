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
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t; // available on 64-bit targets

const int MOD = 998244353;
vector<int> memo;
struct mint {
	int v;
	explicit operator int() const { return v; }
	mint() { v = 0; }
	mint(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mint &operator+=(mint &a, mint b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mint &operator-=(mint &a, mint b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return mint((long long)a.v * b.v); }
mint &operator*=(mint &a, mint b) { return a = a * b; }
mint pow(mint a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mint inv(mint a) {
	assert(a.v != 0);
    if(memo[a.v] == -1){
        memo[a.v] = pow(a, MOD - 2).v;
    } 
    return mint(memo[a.v]);
}
mint operator/(mint a, mint b) { return a * inv(b); }
mint &operator/=(mint &a, mint b) { return a = a / b; }

void solve(){
    int n;
    cin >>n;
    memo.assign(n+5,-1);
    if(n==1){
        cout << "1\n";
        return;
    }
    set<pii> s; vector<mint> a(n+1);
    vector<vii> updates(2*n+5);
    mint prod = 1;
    for(int i=1;i<=n;i++){
        prod*=i;
        updates[i].pb({n-i+1, i});
    }
    for(int i=0;i<n;i++){
        int z = updates[i].size();
        for(int j=0;j<z;j++){
            pii cur = updates[i][j];
            prod /= cur.ff;
            cur.ff--;
            prod *= cur.ff;
            updates[i+cur.ss].pb({cur});
        }
        a[i] = prod;
        //cout << a[i] << "!\n";
    }
    vector<mint> ans(n+1,0);
    vector<vi> u(2*n+5);
    for(int i=1;i<=n;i++){
        u[max(2LL,i)].pb(i);
        if(i>1) continue;
        int num = n-(1/i)-i+1; 
        mint res = (num>0 ? a[1] / (mint)num : 0);
        //cout << "h of " << i << " and " << 1 << " is " << res << "\n";
        ans[i]+=res;
    }
    for(int s=2;s<n;s++){
        int z = u[s].size();
        for(int i=0;i<z;i++){
            int cur = u[s][i];
            u[s+cur].pb(cur);
            int num = n-(s/cur)-cur+1;
            mint res = (num>0 ? a[s] / (mint)num : 0);
            //cout << "h of " << cur << " and " << s << " is " << res << "\n";
            ans[cur]+=res;
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i].v << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}