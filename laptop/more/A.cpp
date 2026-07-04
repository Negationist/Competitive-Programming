#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9+7;

ll euclid(ll a, ll b, ll &x, ll &y){
    if(!b) return x = 1, y = 0, a;
    ll d = euclid(b, a%b, y, x);
    return y -= a/b * x, d;
}

struct Mod {
    ll x;
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) {return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) {return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) {return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) {return *this * invert(b); }
    Mod invert(Mod a){
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1); return Mod((x + mod) % mod);
    }
    Mod operator^(ll e){
        if(!e) return Mod(1);
        Mod r = *this ^ (e/2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

void solve(){
    int n,k;
    cin >> n >> k;
    if(n==1){
        cout << "1\n";
        return;
    }
    int l = 1, r = n;
    set<int> idxs;
    while(l < r){
        int m = (l+r)/2;
        idxs.insert(m);
        l = m + 1;
    }
    int cnt = sz(idxs);
    ++cnt; //this is for the thing on the right being a zero, and youll never check it
    Mod p(1);
    if(k-1 >= cnt){
        for(int i=k-cnt; i<=k-1; i++){
            p = p * i;
        }
        Mod denom(1);
        for(int i=n-cnt+1; i<=n; i++){
            denom = denom * i;
        }
        p = p / denom;
        p = Mod(1) - p;
    }
    p = p / Mod(n-k+1);
    cout << p.x << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}