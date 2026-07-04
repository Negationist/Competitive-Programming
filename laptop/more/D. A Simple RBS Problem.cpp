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

pii get_rep(string s){
    int res = 0;
    int n = (int)s.size();
    int chi[n] = {}, level[n] = {};
    int inc = 0;
    stack<int> outer;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            if(outer.size() > 0){
                int par = outer.top();
                chi[par]++;
            }
            level[(int)outer.size()]++;
            outer.push(inc++);
        } else{
            outer.pop();
        }
    }
    for(int i=0;i<inc;i++){
        if(chi[i] == 0) ++res;
    }
    int p = -1;
    for(int i=0;i<n;i++){
        if(level[i] > 1){
            p = i;
            break;
        }
    }
    return {res, p};
}

void solve(){
    int n; cin >> n;
    string s,t; cin >> s >> t;
    if(get_rep(s) == get_rep(t)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
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