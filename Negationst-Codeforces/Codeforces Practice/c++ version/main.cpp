#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 1e9+7;
void solve(){
    int n;
    cin >> n;
    auto pow = [&](int a,int b){
        int res =1;
        while(b){
            if(b%2){
                res = (res*a)%mod;
            }
            b/=2;
            a = (a*a)%mod;
        }
        return res;
    };
    vi a(n);
    int sum = 0;
    vector<pii> stck;
    for(int i=0;i<n;i++){
        cin >> a[i];
        int r = __builtin_ctz(a[i]);
        int b = a[i]>>r;
        while(stck.size()){
            if(r>=30 || stck.back().first <= (b<<r)){
                r+=stck.back().second;
                sum+=stck.back().first;
                stck.pop_back();
            } else{
                break;
            }
        }
        if(r==0){
            sum+=b;
        } else{
            stck.push_back({b,r});
        }
        int res = sum;
        for(auto x : stck){
            int cur = x.first%mod * pow(2LL,x.second);
            res+=cur;
        }
        cout << res%mod << " ";
    }
    cout << "\n";
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
