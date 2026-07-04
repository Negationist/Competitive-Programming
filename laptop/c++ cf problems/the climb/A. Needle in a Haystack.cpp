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
    map<string, string> m;
    for(int i=0;i<75;i++){
        string a,b;
        cin >> a >> b;
        a.pop_back();
        m[a] = b;
    }
    while(true){
        string s;
        cin >> s;
        cout << "the answer to " << s << " is " << m[s] << "\n";
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}