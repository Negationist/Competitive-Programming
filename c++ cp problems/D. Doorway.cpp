#include <bits/stdc++.h>
#define int long long 
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
    int n;
    cin >> n;
    vector<vi> walls(n, vi());
    vector<vi> sum(n,vi(2));
    multiset<int> left, right;
    set<tuple<int,int,int>> events;
    for(int i=0;i<n;i++){
        int k; cin >> k;
        int x1, x2; cin >> x1 >> x2;
        sum[i][0] = x1;
        sum[i][1] = x2;
        for(int j=0;j<k;j++){
            int z;
            cin >> z;
            sum[i][0]+=z;
            walls[i].pb(z);
        }
        if(k){
            events.insert({sum[i][0], i, k-1});
        }
        left.insert(sum[i][0]);
        right.insert(sum[i][1]);
    }
    auto get = [&](){
        return *right.begin() - *left.rbegin();
    };
    int ans = max(0LL, get());
    while(events.size()){
        auto [l, idx1, idx2] = *events.rbegin();
        left.erase(left.find(sum[idx1][0]));
        right.erase(right.find(sum[idx1][1]));
        sum[idx1][0]-=walls[idx1][idx2];
        sum[idx1][1]-=walls[idx1][idx2];
        left.insert(sum[idx1][0]);
        right.insert(sum[idx1][1]);
        events.erase({l,idx1,idx2});
        if(idx2){
            events.insert({sum[idx1][0], idx1, idx2-1});
        }
        ans = max(ans, get());
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}