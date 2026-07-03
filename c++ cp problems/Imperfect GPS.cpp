#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n;
    ld t;
    cin >> n >> t;
    ld p[n+1][3];
    ld end_t;
    ld a_dist = 0;
    for(int i=0;i<n;i++){
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        if(i==n-1){
            end_t = p[i][2];
        }
        if(i){
            ld temp = (p[i][0]-p[i-1][0]) * (p[i][0]-p[i-1][0]) + (p[i][1]-p[i-1][1]) * (p[i][1]-p[i-1][1]);
            a_dist += sqrt(temp);
        }
    }
    p[n][0] = 0; p[n][1] = 0; p[n][2] = 1e7; //dummy point
    double inc = 0;
    vector<double> times;
    while(inc<end_t){
        times.pb(inc);
        inc+=t;
    }
    times.pb(end_t);
    int j = 0;
    ld opx = p[0][0], opy = p[0][1]; //last recorded
    ld r_dist = 0;
    for(auto time : times){
        while(p[j+1][2] <= time) ++j;
        ld dx = p[j+1][0] - p[j][0], dy = p[j+1][1] - p[j][1];
        ld f = (time-p[j][2]) / (p[j+1][2]-p[j][2]);
        ld px = p[j][0] + f*dx, py = p[j][1] + f*dy;
        r_dist += sqrt((opx-px) * (opx-px) + (opy-py) * (opy-py));
        opx = px;
        opy = py;
    }
    cout << fixed << setprecision(16);
    cout << (a_dist-r_dist) / a_dist * 100.0 << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}