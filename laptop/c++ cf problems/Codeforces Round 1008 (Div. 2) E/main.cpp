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

int ask(int x){
    cout << x << " \n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}
int recieve(){
    cout << "! \n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}
const int maxB = 30;
void solve(){
    int a = 0, b = 0;
    //a has odd bits, b has even bits
    for(int i=0;i<maxB;i++){
        if(i&1){
            a+=(1LL<<i);
        } else{
            b+=(1LL<<i);
        }
    }
    int state[maxB] = {}; //0 = 0, 1 = 1, 2 = 2
    int r1 = ask(a)-2*a;
    //cout << r1 << "!\n";
    for(int i=0;i<maxB+1;i++){
        if(r1&(1LL<<i)){
            if(i&1){
                state[i-1] = 2;
            } else{
               state[i] = 1;
            }
        }
    }
    int r2 = ask(b)-2*b;
    //cout << r2 << "!\n";
    for(int i=0;i<maxB+1;i++){
        if(r2&(1LL<<i)){
            if(!(i&1)){
                state[i-1] = 2;
            } else{
                state[i] = 1;
            }
        }
    }
    int m = recieve();
    int out = 0;
    for(int i=0;i<maxB;i++){
        if(m&(1LL<<i)){
            out+=(2*((1LL<<i)));
        } else{
            out+=(state[i]*(1LL<<i));
        }
    }
    cout << out << "\n";
    cout.flush();
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
