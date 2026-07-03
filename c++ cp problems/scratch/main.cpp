#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int dx[4] = {-1,-1,1,1}, dy[4] = {1,-1,1,-1};

void solve(){
    int a,b;
    cin >> a >> b;
    int x1,y1,x2,y2,ans=0;
    cin >> x1 >> y1 >> x2 >> y2;
    set<pii> K;
    set<pii> Q;
    for(int i=0;i<4;i++){
        K.insert({x1+dx[i]*a, y1+dy[i]*b});
        K.insert({x1+dx[i]*b, y1+dy[i]*a});
        Q.insert({x2+dx[i]*a, y2+dy[i]*b});
        Q.insert({x2+dx[i]*b, y2+dy[i]*a});
    }
    for(auto x : K){
        if(Q.find(x) != Q.end()){
            ans++;
        }
    }
    cout << ans << "\n";
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
