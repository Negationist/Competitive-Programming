#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int mod = 1e9+7;

vector<int> matrixMult(vector<int> a, vector<int> b){
    vector<int> res(4);
    res[0] = (a[0]*b[0])%mod+(a[1]*b[2])%mod;
    res[0]%=mod;
    res[1] = (a[0]*b[1])%mod+(a[1]*b[3])%mod;
    res[1]%=mod;
    res[2] = (a[2]*b[0])%mod+(a[3]*b[2])%mod;
    res[2]%=mod;
    res[3] = (a[2]*b[1])%mod+(a[3]*b[3])%mod;
    res[3]%=mod;
    return res;
}

vector<int> matrixPow(vector<int> base, int p){
    vector<int> res = {1,0,0,1};
    while(p>0){
        if(p&1){
            res = matrixMult(res,base); //MOD OR NO MOD
        }
        p/=2;
        base = matrixMult(base,base); // MOD OR NO MOD
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    while(n--){
        int z;
        cin >> z;
        vector<int> fib = {1,1,1,0};
        cout << matrixPow(fib,z,1);
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
