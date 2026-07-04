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
using tiii = tuple<int,int,int,int>;  //x,y,time,color

void solve(){
    int h,w;
    cin >> h >> w;
    vector<string> g(h);
    queue<tiii> q;
    vector<vii> s(h,vii(w,{1LL<<30,-1}));
    int inc = 0;
    auto push_around = [&](int x, int y, int t, int c)->void{
        if(x-1>=0){
            q.push({x-1,y,t+1,c});
        }
        if(y-1>=0){
            q.push({x,y-1,t+1,c});
        }
        if(x+1<h){
            q.push({x+1,y,t+1,c});
        }
        if(y+1<w){
            q.push({x,y+1,t+1,c});
        }
    };
    auto check = [&](int x, int y, int t, int c)->bool{
        if(x-1>=0){
            if(s[x-1][y].ff<t && s[x-1][y].ss!=c){
                return false;
            }
        }
        if(y-1>=0){
            if(s[x][y-1].ff<t && s[x][y-1].ss!=c){
                return false;
            }
        }
        if(x+1<h){
            if(s[x+1][y].ff<t && s[x+1][y].ss!=c){
                return false;
            }
        }
        if(y+1<w){
            if(s[x][y+1].ff<t && s[x][y+1].ss!=c){
                return false;
            }
        }
        return true;
    };
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> g[i][j];
            if(g[i][j]=='S'){
                s[i][j] = {0,++inc};
                push_around(i,j,0,inc);
            }
        }
    }
    while(q.size()){
        tiii cur = q.front();
        q.pop();
        int x = get<0>(cur), y = get<1>(cur), t = get<2>(cur), c = get<3>(cur);
        if(s[x][y].ss==-1 && check(x,y,t,c)){
            s[x][y] = {t,c};
            push_around(x,y,t,c);
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j].ss==-1) continue;
            if(!i){
               ++ans;
            } else{
                if(s[i][j].ss!=s[i-1][j].ss){
                    ++ans;
                }
            }
            if(!j){
               ++ans;
            } else{
                if(s[i][j].ss!=s[i][j-1].ss){
                    ++ans;
                }
            }
            if(i+1==h){
               ++ans;
            } else{
                if(s[i][j].ss!=s[i+1][j].ss){
                    ++ans;
                }
            }
            if(j+1==w){
               ++ans;
            } else{
                if(s[i][j].ss!=s[i][j+1].ss){
                    ++ans;
                }
            }
        }
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