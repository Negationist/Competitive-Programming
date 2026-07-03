#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int maxN = 2e5+5;
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

int binPow(int b, int p){
    int res = 1;
    while(p>0){
        if(p&1){
            res*=b;
            if(res>(maxN*maxN)) return 0;
        }
        p>>=1;
        b = b*b;
        if(b>(maxN*maxN)) return 0;
    }
    return res;
}

void solve(){
    int n,k;
    cin >> n >> k;
    map<int,int> m;
    vi a(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        map<int,int> d;
        while(z>1){
            int cur = sieve[z];
            d[cur]++;
            d[cur]%=k;
            z/=cur;
        }
        int res = 1;
        for(auto x : d){
            res*=binPow(x.ff, x.ss);
        }
        a[i] = res;
        m[res]++;
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int z = a[i];
        m[z]--;
        map<int,int> d;
        int target = 1;
        while(z>1){
            int cur = sieve[z];
            d[cur]++;
            d[cur]%=k;
            z/=cur;
        }
        for(auto x : d){
            target*=binPow(x.ff, k-x.ss);
        }
        ans+=m[target];
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
