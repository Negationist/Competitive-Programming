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
using namespace std::chrono;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int inf = 1e9;

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
int mn = 1, mx = 1e5;
uniform_int_distribution<int> dist(mn, mx);

void solve(){
    int n,m;
    cin >> n >> m;
    set<int> d;
    for(int i=0;i<n;i++){
        int z; cin >> z;
        d.insert(z);
    }
    set<int> seen;
    vi add;
    vi q;
    while(m--){
        char c; int v;
        cin >> c >> v;
        if(c=='X'){
            q.pb(-1);
            add.pb(v);
            d.erase(v);
        } else{
            q.pb(v);
        }
    }
    reverse(all(q));
    int dp[(int)(1e5+1)];
    dp[0] = 0;
    for(int i=1;i<=1e5;i++){
        dp[i] = inf;
    }
    //auto start = high_resolution_clock::now();
    vi bruh;
    for(int x : d){
        bruh.pb(x);
    }
    for(int i=0;i<=1e5;i++){
        for(int x : bruh){
            if(x<=i){
                dp[i] = min(dp[i],dp[i-x]+1);
            }
        }
    }
    //auto end = high_resolution_clock::now();
    //auto duration = duration_cast<milliseconds>(end - start);
    //cout << "Execution time: " << duration.count() << " ms\n";
    vi out;
    for(int x : q){
        if(x==-1){
            int cur = add.back();
            add.pop_back();
            for(int i=0;i<=1e5;i++){
                if(cur<=i){
                    dp[i] = min(dp[i],dp[i-cur]+1);
                }
            }
        } else{
            out.pb((dp[x]==inf?-1:dp[x]));
        }
    }
    reverse(all(out));
    for(int x : out){
        cout << x << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // set<int> s;
    // while(s.size()<2000){
    //     int z = dist(rng);
    //     if(s.find(z)==s.end()){
    //         s.insert(z);
    //     }
    // }
    // for(int x : s){
    //     cout << x << " ";
    // }
    // return 0;
    solve();
    return 0;
}