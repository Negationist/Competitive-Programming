#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int r,c,n,p;
    cin >> r >> c >> n >> p;
    pii pos[n+1];
    int q[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> q[i][j];
            if(q[i][j]){
                pos[q[i][j]] = {i,j};
            }
        }
    }
    set<int> delta;
    for(int i=p;i>=1;i--){
        int x = pos[i].ff, y = pos[i].ss;
        if(x){
            if(q[x-1][y]){
                delta.insert(q[x-1][y]-i);
            }
        }
        if(x<r-1){
            if(q[x+1][y]){
                delta.insert(q[x+1][y]-i);
            }
        }
        if(y){
            if(q[x][y-1]){
                delta.insert(q[x][y-1]-i);
            }
        }
        if(y<c-1){
            if(q[x][y+1]){
                delta.insert(q[x][y+1]-i);
            }
        }
    }
    int ans = 0;
    for(int x : delta){
        int person = p+x;
        if(person>=1 && person<=n){
            ++ans;
        }
    }
    cout << ans << "/" << n-1 << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
