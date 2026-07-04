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
    int w,h,x_s,y_s,n;
    cin >> w >> h >> x_s >> y_s >> n;
    map<int, vi> x_b, y_b;
    map<pii, int> visited;
    queue<pair<pii,int>> q;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        x_b[a].pb(b);
        y_b[b].pb(a);
    }
    for(auto l : x_b){
        sort(l.ss.begin(),l.ss.end());
    }
    q.push({{x_s,y_s},0});
    while(q.size()){
        auto [x,y] = q.front().ff;
        int num = q.front().ss;
        q.pop();
        visited[cur] = 1;
        auto it = lower_bound(x_b[x].begin(), x_b[x].end(), y);
        if(it==x_b.end() || it==x_b.begin()){
            cout << num << "\n";
            return;
        } else{
            int above = *it;
            it--;
            int below = *it;
            if(!visited[{x,above}]){
                q.push({{x,above},num+1});
            }
            if(!visited[{x,below}]){
                q.push({{x,below},num+1});
            }
        }
        it = lower_bound(y_b[y].begin(), y_b[y].end(), x);
        if(it==y_b.end() || it==y_b.begin()){
            cout << num << "\n";
            return;
        } else{
            int above = *it;
            it--;
            int below = *it;
            if(!visited[{above,y}]){
                q.push({{above,y},num+1});
            }
            if(!visited[{below,y}]){
                q.push({{below,y},num+1});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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