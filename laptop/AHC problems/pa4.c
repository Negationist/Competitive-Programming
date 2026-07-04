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
        vi pref(n+1);
        pref[0] = 0;
        multiset<pii> prefs;
        int x = -1, y = 0, mx = -10;
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1]+c[i];
            prefs.insert({pref[i], -i}); //lower index = we want
        }
        for(int i=1;i<=n;i++){ //we have to include this letter
            pii best = *prefs.rbegin();
            int res = best.ff - pref[i-1];
            if(res > mx){
                mx = res;
                x = i;
                y = -best.ss;
            }
            prefs.erase(prefs.find({pref[i], -i}));
        }
        return make_tuple(-mx,x,y);
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