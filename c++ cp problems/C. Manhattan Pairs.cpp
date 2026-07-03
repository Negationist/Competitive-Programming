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

void solve(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> a(n);
    for(int i=0;i<n;i++){
        int y,z; cin >> y >> z;
        a[i] = {y,z,i+1};
    }
    sort(all(a));
    set<tuple<int,int,int>> l,r,t,b;
    for(int i=0;i<n;i++){
        if(i<n/2){
            l.insert(a[i]);
        } else{
            r.insert(a[i]);
        }
        swap(get<0>(a[i]),get<1>(a[i]));
    }
    sort(all(a));
    for(int i=0;i<n;i++){
        swap(get<0>(a[i]),get<1>(a[i]));
        if(i<n/2){
            b.insert(a[i]);
        } else{
            t.insert(a[i]);
        }
    }
    vector<tuple<int,int,int>> lt, lb, rt, rb;
    for(auto z : l){
        if(t.find(z)!=t.end()){
            lt.pb(z);
        } else{
            lb.pb(z);
        }
    }
    for(auto z : r){
        if(t.find(z)!=t.end()){
            rt.pb(z);
        } else{
            rb.pb(z);
        }
    }
    for(int i=0;i<sz(lt);i++){
        cout << get<2>(lt[i]) << " " << get<2>(rb[i]) << "\n";
    }
    for(int i=0;i<sz(lb);i++){
        cout << get<2>(lb[i]) << " " << get<2>(rt[i]) << "\n";
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