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

template <typename T, auto M> struct Mod {
  using V = conditional_t<sizeof(T) <= 4, u64, u128>;
  static V inv(V x, V m) { return x > 1 ? m - inv(m % x, x) * m / x : 1; }
  make_unsigned_t<T> x;
  Mod() : x(0) {}
  Mod(auto y) : x(y % M) { x >= M ? x += M : x; }
  operator T() const { return x; }
  Mod operator-() const { return Mod() -= *this; }
  Mod operator+(auto rhs) const { return Mod(*this) += rhs; }
  Mod operator-(auto rhs) const { return Mod(*this) -= rhs; }
  Mod operator*(auto rhs) const { return Mod(*this) *= rhs; }
  Mod operator/(auto rhs) const { return Mod(*this) /= rhs; }
  Mod &operator+=(Mod rhs) { return (x += rhs.x) >= M ? x -= M : x, *this; }
  Mod &operator-=(Mod rhs) { return (x -= rhs.x) >= M ? x += M : x, *this; }
  Mod &operator*=(Mod rhs) { return x = x * V(rhs.x) % M, *this; }
  Mod &operator/=(Mod rhs) { return x = x * inv(rhs.x, M) % M, *this; }
  Mod pow(auto y) const {
    Mod ans(1), base(*this);
    for (auto e = y < 0 ? ~y + u128(1) : +y; e; e >>= 1, base *= base) {
      e & 1 ? ans *= base : ans;
    }
    return y < 0 ? Mod(1) /= ans : ans;
  }
};

constexpr int mod = 998244353;
using mint = Mod<int, mod>;

void solve(){
    int n;
    cin >>n;
    if(n==1){
        cout << "1\n";
        return;
    }
    set<pii> s; vi a(n+1);
    vector<vii> updates(2*n+5);
    mint prod = 1;
    for(int i=1;i<=n;i++){
        prod*=i;
        updates[i].pb({n-i+1, i});
    }
    for(int i=0;i<=n;i++){
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
        mint res = (num>0 ? a[1] / num : 0);
        //cout << "h of " << i << " and " << 1 << " is " << res << "\n";
        ans[i]+=res;
    }
    for(int s=2;s<n;s++){
        int z = u[s].size();
        for(int i=0;i<z;i++){
            int cur = u[s][i];
            u[s+cur].pb(cur);
            int num = n-(s/cur)-cur+1;
            mint res = (num>0 ? a[s] / num : 0);
            //cout << "h of " << cur << " and " << s << " is " << res << "\n";
            ans[cur]+=res;
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}