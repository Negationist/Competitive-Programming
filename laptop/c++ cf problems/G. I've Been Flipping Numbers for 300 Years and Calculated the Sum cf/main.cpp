#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
const int mod = 1e9+7;
int binPowMod(int b, int p, int mod){
    int res = 1;
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

int ans(int n,int k){
    int res = 0;
    for(int i=2;i<=k;i++){
        int temp = n;
        vi d;
        while(temp>0){
            d.pb(temp%i);
            temp/=i;
        }
        int sze = d.size();
        for(int j=0;j<sze;j++){
            res+=(d[j]*binPowMod(i,sze-1-j,mod));
        }
    }
    return res;
}

void solve(){
    int n,k;
    cin >> n >> k;
    for(int i=3;i<=k;i++){
        cout << "n is " << n << ". k is " << i << "\n";
        cout << ans(n,i)-ans(n,i-1) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
