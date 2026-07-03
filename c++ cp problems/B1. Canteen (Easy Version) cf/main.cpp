#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;

ll mod = 2e18;

ll binPowMod(ll b, ll p, ll mod){
    ll res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}

ll modInv(ll x, ll mod){
    return binPowMod(x,mod-2,mod);
}

void solve(){
    int x;
    cin >> x;
    int ans = LLONG_MAX;
    for(int i=2;i<=60;i++){
        long double res1 = pow(x,(double)(1.0/i));
        int res = round(res1);
        for(int j=max(1LL,res-1);j<=res+1;j++){
            int num = 2;
            for(int k=2;k<sqrtl(j);k++){
                if(j%k==0){
                    num+=2;
                }
            }
            int root = sqrtl(j);
            if(root*root==j) num++;
            int res2 = binPowMod(j,num,mod);
            if(res2==x){
                ans = min(ans,j);
            }
        }
    }
    cout << (ans==LLONG_MAX?-1:ans) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
