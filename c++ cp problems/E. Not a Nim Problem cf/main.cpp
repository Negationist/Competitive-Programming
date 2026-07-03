#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
const int maxN = 1e7+5;
int g[maxN];
int sieve[maxN] = {};

void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                if(sieve[j]==j){
                    sieve[j] = i;
                }
            }
        }
    }
    g[0] = 0;
    g[1] = 1;
    int inc = 1;
    for(int i=2;i<maxN;i++){
        if(!(i&1)){
            g[i] = 0;
        } else{
            if(sieve[i]==i){
                g[i] = ++inc;
            } else{
                g[i] = g[sieve[i]];
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int res = 0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        res^=g[z];
    }
    if(res){
        cout << "Alice\n";
    } else{
        cout << "Bob\n";
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
