#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
int mn = 1, mx = 1e6;
uniform_int_distribution<int> dist(mn, mx);


void solve(){
    ofstream  file("stComDiv2.txt");
    file << 2*1e4 << "\n";
    for(int i=0;i<2*1e4;i++){
        file << dist(rng) << " ";
    }
    file << "\n";
    file.close();
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
