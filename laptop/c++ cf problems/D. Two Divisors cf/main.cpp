#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int maxN = 1e7+5;

vector<int> d(maxN,-1);
vi sieve(maxN);
void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=2*i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
    for(int i=2;i<maxN;i++){
        if(!(i&1) || sieve[i]!=i) continue;
        for(int j=i;j<maxN;j+=i){
            if(d[j]==-1){
                d[j] = i;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    int out[n][2];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        if(a[i]&1){
            int x = 1;
            int og = a[i];
            while(a[i]%d[og]==0){
                x*=d[og];
                a[i]/=d[og];
            }
            if(__gcd(x+a[i],og)==1 && a[i]!=1){
                out[i][0] = x;
                out[i][1] = a[i];
            } else{
                out[i][0] = out[i][1] = -1;
            }
        } else{
            int x = 1;
            while(!(a[i]&1)){
                x<<=1;
                a[i]>>=1;
            }
            if(a[i]!=1){
                out[i][0] = x;
                out[i][1] = a[i];
            } else{
                out[i][0] = out[i][1] = -1;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cout << out[j][i] << " ";
        }
        cout << "\n";
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
