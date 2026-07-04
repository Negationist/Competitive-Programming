#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

struct Line {
mutable ll k, m, p;
bool operator<(const Line& o) const { return k < o.k; }
bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
// ( for doubles , use in f = 1/.0 , div (a , b) = a/b)
static const ll inf = LLONG_MAX;
ll div(ll a, ll b) { // f loored division
return a / b - ((a ^ b) < 0 && a % b); }
bool isect(iterator x, iterator y) {
if (y == end()) return x->p = inf, 0;
if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
else x->p = div(y->m - x->m, x->k - y->k);
return x->p >= y->p;
}
void add(ll k, ll m) {
auto z = insert({k, m, 0}), y = z++, x = y;
while (isect(y, z)) z = erase(z);
if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
while ((y = x) != begin() && (--x)->p >= y->p)
isect(x, erase(y));
}
ll query(ll x) {
assert(!empty());
auto l = *lower_bound(x);
return l.k * x + l.m;
}
};


void solve(){
    int n;
    cin >> n;
    int  mx_h = -1, idx = -1;
    vi h(n), w(n);
    for(int i=0;i<n;i++){
        cin >> h[i]  >> w[i];
        if(h[i] > mx_h){
            idx = i;
            mx_h = h[i];
        }
    }
    auto solve = [&](){

    };
    vi temp_h(n), temp_w(n);
    for(int i=0;i<n;i++){
        temp_h.pb(h[(idx+i)%n]);
        temp_w.pb(w[(idx+i)%n]);
    }
    h = temp_h;
    w = temp_w;
    
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}