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

const int inf = 1e16;

void solve(){
    int D;
    cin >> D;
    int c[26];
    for(int i=0;i<26;i++) cin >> c[i];
    int s[D][26];
    for(int i=0;i<D;i++){
        for(int j=0;j<26;j++){
            cin >> s[i][j];
        }
    }
    int last[26] = {};
    auto priority = [&](int i, int day){
        int res = c[i]*(day - last[i]) + s[day][i]; //higher penalty = do this one, higher benefit = do this one
        return res;
    };
    int day = 0;
    vi out;
    while(day < D){
        int idx = -1, mx = -inf;
        for(int i=0;i<26;i++){
            if(priority(i, day) > mx){
                mx = priority(i,day);
                idx = i;
            }
        }
        last[idx] = day;
        out.pb(idx);
        ++day;
    }
    for(int x : out){
        cout << x+1 << "\n";
    }
    auto get_score = [&](vi &out){
        for(int i=0;i<26;i++) last[i] = 0;
        int day = 0;
        while(day < D){
            
        }
    }
    //cout << "your score was " << score + (ll)(1e6) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}