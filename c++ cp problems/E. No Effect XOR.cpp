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

void solve(){
    int l,r;
    cin >> l >> r;
    set<int> base;
    for(int i=l;i<=r;i++){
        base.insert(i);
    }
    vi ans;
    for(int i=1;i<=1000;i++){
        set<int> temp;
        for(int x : base){
            temp.insert(x^i);
        }
        if(temp == base){
            ans.pb(i);
        }
    }
    for(int x : ans){
        cout << x << "\n";
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