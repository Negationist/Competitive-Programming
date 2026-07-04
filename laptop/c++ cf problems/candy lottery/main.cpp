#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

long double binPow(long double b, int p){
    long double res = 1;
    while(p>0){
        if(p&1){
            res*=b;
        }
        p>>=1;
        b = b*b;
    }
    return res;
}


void solve(){
    int n,k;
    cin >> n >> k;
    long double ans = 0;
    for(int i=1;i<=k;i++){
        long double res = 0;
        res+=binPow((long double)(i)/k,n);
        res-=binPow((long double)(i-1)/k,n);
        ans+=(i*res);
    }
    cout << fixed << setprecision(6) << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
