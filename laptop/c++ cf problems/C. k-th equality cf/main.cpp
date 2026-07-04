#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int binPow(int b, int p){
    int res = 1;
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
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    pii cRange = {binPow(10,c-1), binPow(10,c)-1};
    for(int i=binPow(10,a-1);i<=binPow(10,a)-1;i++){
        int l = cRange.ff-i, r = cRange.ss-i;
        if(l<binPow(10,b-1)){
            l = binPow(10,b-1);
        }
        if(r>binPow(10,b)-1){
            r = binPow(10,b)-1;
        }
        int cnt = max(0LL,r-l+1);
        if(k>cnt){
            k-=cnt;
        } else{
            cout << i << " + " << l+(k-1) << " = " << i+l+(k-1) << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
