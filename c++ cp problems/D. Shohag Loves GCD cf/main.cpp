#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int maxN = 1e5+5;
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
    int n,m;
    cin >> n >> m;
    vi a(m);
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    int num = 31-__builtin_clz(n);
    if(num+1>m){
        cout << -1 << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        int inc = 0;
        int cur = i;
        while(cur>1){
            inc++;
            cur/=sieve[cur];
        }
        cout << a[m-1-inc] << " ";
    }
    cout << "\n";
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
