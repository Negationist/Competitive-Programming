#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    mt19937_64 rng(seed);
    int mn = 1, mx = 1LL<<63;
    uniform_int_distribution<int> dist(mn, mx);
    int inc = 0;
    for(int i=0;i<1000000;i++){
        int x = dist(rng);
        int y = dist(rng);
        inc+=(gcd(x,y)==1);
    }
    cout << (long double)(inc)/1000000 << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
