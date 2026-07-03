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
using u128 = unsigned __int128;
using i128 = __int128;
map<ll,ll> out;
map<ll,ll> in;
set<ll> keys;
i128 a = 4873901283746502931, b = 8439172053812765407, c = 7129384610573821945, d = 1e18;

ll get_rand(){
    a = (a*b+c)%d;
    return (ll)a;
}

void gen_keys(){
    for(int i=1;i<=1e6;i++){
        ll res = get_rand();
        while(keys.find(res)!=keys.end()){
            res = get_rand();
        }
        keys.insert(res);
        out[i] = res;
        in[res] = i;
    }
}
void solve(){
    string s;
    cin >> s;
    ll cur = 0;
    if(s=="resume") cin >> cur;
    ll num; cin >> num;
    while(num--){
        ll z;
        cin >> z;
        cur^=out[z];
        if(cur==0){
            cout << "0\n";
        } else if(keys.find(cur)!=keys.end()){
            cout << in[cur] << "\n";
        } else{
            cout << "-1\n";
        }
    }
    if(s=="start") cout << cur << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    gen_keys();
    solve();
    return 0;
}
