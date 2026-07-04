#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = "?"+s;
    vi a(n+1); //uva is positive
    vi b(n+1);
    for(int i=1;i<=n;i++){
        a[i] = (s[i] == 'B'? 1 : -1);
        b[i] = -a[i];
    }
    auto gett = [&](vi &c){
        int x, y, mx = -10, l;
        int sum = -1;
        for(int i=1;i<=n;i++){
            if(sum < 0){
                l = i;
                sum = c[i];
            } else{
                sum+=c[i];
            }
            if(sum > mx){
                mx = sum;
                x = l;
                y = i;
            }
        }
        return make_tuple(-mx, x, y);
    };
    tuple<int,int,int> uva = gett(a); //low, low, low
    tuple<int,int,int> vt = gett(b); 
    if(uva < vt){ //lower is better for all
        cout << "UVa\n";
        cout << get<1>(uva) << " " << get<2>(uva) << "\n";
    } else{
        cout << "VT\n";
        cout << get<1>(vt) << " " << get<2>(vt) << "\n";
    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}