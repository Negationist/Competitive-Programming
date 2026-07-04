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

void solve(){
    int n;
    cin >> n;
    vector<vi> adj(n);
    vector<tuple<int,int,int>> d(n);
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        d[i] = {a,b,c};
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int dx = (get<0>(d[i])-get<0>(d[j]));
            int dy = (get<1>(d[i])-get<1>(d[j]));
            i128 dist1 = dx*dx+dy*dy;
            i128 dist2 = get<2>(d[i])+get<2>(d[j]);
            dist2*=dist2;
            if(dist1==dist2){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    set<int> avail;
    for(int i=0;i<n;i++) avail.insert(i);
    vi color(n,2);
    int white,black;
    auto two_color = [&](auto self, int x, int tag, vi&color)->bool{
        bool bad = false;
        color[x] = tag;
        avail.erase(x);
        if(tag==0) ++white;
        else ++black;
        for(int y : adj[x]){
            if(color[y]==2){
                bad|=(self(self,y,1-tag,color));
            } else{
                if(color[y]==color[x]){
                    bad = true;
                }
            }
        }
        return bad;
    };
    while(avail.size()){
        white = black = 0;
        //cout << "start!\n";
        if(!two_color(two_color, *avail.begin(),0,color)){
            if(white!=black){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
