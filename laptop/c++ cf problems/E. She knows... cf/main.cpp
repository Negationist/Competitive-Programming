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
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
const int mod = 1e9+7;
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
    int n,m,k;
    cin >> n >> m >> k;
    set<pii> cells;
    map<pii,int> color;
    for(int i=0;i<k;i++){
        int x,y,c;
        cin >> x >> y >> c;
        cells.insert({--x,--y});
        color[{x,y}] = c;
    }
    bool flag = false;
    for(int i=1;i<m-1;i++){
        if(cells.find({0,i})==cells.end()){
            flag = true;
            break;
        }
        if(cells.find({n-1,i})==cells.end()){
            flag = true;
            break;
        }
    }
    for(int i=1;i<n-1;i++){
        if(cells.find({i,0})==cells.end()){
            flag = true;
            break;
        }
        if(cells.find({i,m-1})==cells.end()){
            flag = true;
            break;
        }
    }
    auto is_white = [&](int x, int y){
        if(x<0 || x>=n) return false;
        if(y<0 || y>=m) return false;
        if(color[{x,y}] == 0){
            //cout << x << " " << y << "!\n";
            return true;
        }
        return false;
    };
    if(flag){
        int ans = binPowMod(2,n*m-k-1,mod);
        cout << ans << "\n";
    } else{
        int num = 0;
        for(auto [x,y] : cells){
            if(color[{x,y}] == 1){
                //cout << x << " " << y << " has: \n";
                num+=is_white(x-1,y);
                num+=is_white(x+1,y);
                num+=is_white(x,y-1);
                num+=is_white(x,y+1);
            }
        }
        //cout << num << "\n";
        if(num&1){
            cout << 0 << "\n";
        } else{
            cout << binPowMod(2,n*m-k,mod) << "\n";
        }
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
