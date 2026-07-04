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
constexpr double pi = 3.14159265358979323846;
int numPoints(vector<vector<int>>& darts, int r) {
    int n = darts.size();
    int ans = 1;
    double dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int dx = darts[i][0]-darts[j][0];
            int dy = darts[i][1]-darts[j][1];
            int delta = dx*dx+dy*dy;
            dist[i][j] = sqrt(delta);
        }
    }
    for(int i=0;i<n;i++){
        vector<pair<double,int>> events;
        for(int j=0;j<n;j++){
            if(i==j || dist[i][j]>2*r) continue;
            int dx = darts[j][0]-darts[i][0];
            int dy = darts[j][1]-darts[i][1];
            double a = atan2(dy,dx);
            double b = acos(dist[i][j]/(2.0*r));
            double alpha = a-b;
            double beta = a+b;
            events.pb({alpha,-1});
            events.pb({alpha-2*pi,-1});
            events.pb({alpha+2*pi,-1});
            events.pb({beta,1});
            events.pb({beta-2*pi,1});
            events.pb({beta+2*pi,1});
        }
        sort(events.begin(),events.end());
        int cnt = 1;
        for(auto x : events){
            cnt-=x.ss;
            ans = max(ans,cnt);
        }
    }
    return ans;
}

void solve(){
    int n,r;
    cin >> n >> r;
    vector<vi> darts(n,vi(2));
    for(int i=0;i<n;i++){
        cin >> darts[i][0] >> darts[i][1];
    }
    int res = numPoints(darts,r);
    cout << res << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
