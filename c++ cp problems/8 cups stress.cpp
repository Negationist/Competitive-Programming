#include <bits/stdc++.h>
#include <quadmath.h>
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
using ld = __float128;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const ld eps = 1e-100;

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
int mn = 0, mx = 3;
uniform_int_distribution<int> dist(mn, mx);

void solve(){
    ll trials = 100000;
    ld sum = 0;
    for(int i=0;i<trials;i++){
        vector<ld> water = {1e300,0,0,0};
        ll num = 0;
        while(++num){
            int x =dist(rng), y;
            while(true){
                y = dist(rng);
                if(x!=y) break;
            }
            ld tot = water[x]+water[y];
            water[x] = water[y] = tot/2.0;
            sort(water.begin(),water.end());
            if(abs(water[0]-water[3])<eps){
                break;
            }
        }
        sum+=num;
    }
    cout << sum/trials << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}