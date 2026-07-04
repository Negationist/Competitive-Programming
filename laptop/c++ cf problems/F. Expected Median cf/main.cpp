#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int memo[200006] = {0};
int MOD = 1e9+7;

int modInverse(int a, int m){
    int num = m-2;
    int res = 1;
    while(num>0){
        if(num%2==1){
            res = (res*a)%MOD;
            num--;
        } else{
            a = (a*a)%MOD;
            num/=2;
        }
    }
    return res;
}

int factorial(int n){
    if (n==0) return 1;
    if (n==1) return 1;
    if(memo[n] != 0) return memo[n];
    memo[n] = (n*(factorial(n-1)%MOD))%MOD;
    return memo[n];
}

int nCr(int n, int r){
    int res = (factorial(n) * modInverse(factorial(n-r),MOD))%MOD;
    res*=modInverse(factorial(r),MOD);
    res%=MOD;
    return res;
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k,ans=0;
        cin >> n >> k;
        int x = 0;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            x+=a;
        }
        int y = n-x;
        for(int i=k/2+1;i<=x;i++){
            if(i>k){
                break;
            }
            if(y < k-i) continue;
            ans+=((nCr(x,i) * nCr(y,k-i))%MOD);
            ans%=MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
