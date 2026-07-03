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
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
ll mn = LLONG_MIN, mx = LLONG_MAX;
uniform_int_distribution<ll> dist(mn, mx);
template <class T>
struct Treap_Node{
    T key; //assumed to be unique keys
    ll pri = dist(rng);
    Treap_Node* l = nullptr;
    Treap_Node* r = nullptr;
    static pair<Treap_Node*, Treap_Node*> split(Treap_Node* x, ll val){
        if(x == nullptr){
            return {nullptr, nullptr};
        }
        if(x->key <= val){
            auto [left, right] = split(x->r, val);
            x->r = left;
            return {x, right};
        } else{
            auto [left, right] = split(x->l, val);
            x->l = right;
            return {left, x};
        }
    }
    static Treap_Node* merge(Treap_Node* x, Treap_Node* y){ //all keys of x are smaller than all keys of y
        if(x == nullptr){
            return y;
        }
        if(y == nullptr){
            return x;
        }
        if(x->pri > y->pri){
            Node* temp = merge(x->r, y);
            x->r = temp;
        } else{
            Node* temp = merge(x, y->l);
            y->l = temp;
        }
    }
    static void insert(Treap_Node* root, Treap_Node* add){
        auto [left, right] = split(root, add->key);
        return merge(merge(left, add), right);
    }
    static bool remove(Treap_Node val){

    }
};

void solve(){
    
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