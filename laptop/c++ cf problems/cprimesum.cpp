#include <bits/stdc++.h>
#define int long long
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

const int maxN = 1e6;

int sieve[maxN] = {};
 
void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
}

void solve(){
    int ans = 0;
    vi p;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            p.pb(i);
        }
    }
    for(int i=1e3;;i--){
        
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}