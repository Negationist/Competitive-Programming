#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    int I,T;
    cin >> I >> T;
    set<pii> states;
    set<pii> forbidden;
    states.insert({I,T});
    for(int i=0;i<n;i++){
        set<pii> nstates;
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(auto [x,y] : states){
            nstates.insert({x,y});
            if(a<=x && x<=b && c<=y && y<=d){
                forbidden.insert({x,y});
                nstates.insert({x+1,y});
                nstates.insert({x,y+1});
            }
        }
        set<pii> nstates2;
        for(auto x : nstates){
            if(forbidden.find(x) == forbidden.end()){
                nstates2.insert(x);
            }
        }
        states = move(nstates2);
    }
    int ans = 0;
    for(auto [x,y] : states){
        ans = max(ans,x+y-I-T);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
