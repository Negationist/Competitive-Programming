#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int mod = 998244353;
const int mx = 1e6+5;
int sieve[mx] = {};
vector<int> primes;

void compute(){
    for(int i=2;i<=mx;i++){
        for(int j=2*i;j<=mx;j+=i){
            sieve[j] = 1;
        }
    }
    for(int i=2;i<=mx;i++){
        if(sieve[i]==0){
            primes.pb(i);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    map<int,int> dp;
    for(int x : primes){
        vector<int> d;
        if(x > sqrt(a[0])) break;
        if(a[0]%x==0){
            dp
            d.pb(x);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    compute();
    while(t--){
        solve();
    }
    return 0;
}
