#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x=1, y=0, a;
    ll d = euclid(b, a%b, y, x);
    return y -= a/b * x, d;
}

const ll mod = 998244353;
struct Mod {
    ll x;
    Mod(ll xx) : x(xx) {}
    Mod operator+ (Mod b) {return Mod((x + b.x) % mod);}
    Mod operator- (Mod b) {return Mod((x - b.x + mod) % mod);}
    Mod operator* (Mod b) {return Mod((x * b.x) % mod);}
    Mod operator/ (Mod b) {return *this * invert(b);}
    Mod invert(Mod a) {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert (g==1); return Mod((x+mod) % mod);
    }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

int main()
{
    //cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    map<pair<int,int>, long long> dp;
    map<pair<int,int>, bool> visited;
    int n; cin >> n;
    auto before = [&](int x, int mod){ //one indexed
        if(mod >= x){
            return 0;
        } else{
            int num = x-1;
            num-=(mod-1);
            return ((num+5)/6);
        }
    };

    //Mod sixth = Mod(1)/Mod(6);

    auto get = [&](auto self, int x, int t)->long long {
        if(x==1 && t==1){
            return 1LL;
        }
        pair<int,int> base = make_pair(x,t);
        if(visited[base]) return dp[base];
        visited[base] = 1;
        //cout << x << " " << t << "!!\n";
        Mod res(0);
        Mod sixth = Mod(1) / Mod(min(t,6));
        for(int i=1;i<=min(t,6);i++){
            int bruh = (x%6);
            if(!bruh){
                bruh = 6;
            }
            if(i == bruh) continue;
            int x_p = x - before(x, i), t_p = t - before(t+1, i);
            // if(x==1 && t==3){
            //     cout << res << "!!!\n";
            // }
            // if(x==1 && t==3){
            //     cout << "x_p is " << x_p << ". t_p is " << t_p << "\n";
            //     cout << "add is " << self(self, x_p, t_p) * sixth << "\n";
            // }
            res = res + (Mod(self(self, x_p, t_p)) * sixth);
            // if(x==1 && t==3){
            //     cout << res << "!!\n";
            // }
        }
        dp[base] = res.x;
        //cout << "dp " << x << " " << t << " is " << res.x << "\n";
        return res.x;
    };
    for(int i=1;i<=n;i++){
        cout << get(get,i,n) << "\n";
    }
}
