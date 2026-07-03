#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

void solve(){
    int n,e;
    cin >> n >> e;
    vii hate(e);
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        hate[i]={--x,--y};
    }
    vector<vi> choices(n);
    int T = -1;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        choices[i].resize(z);
        for(int j=0;j<z;j++){
            cin >> choices[i][j];
            --choices[i][j];
            T = max(T,choices[i][j]+1);
        }
    }
    vi colors(T);
    vi team(n);
    vi desig(n);
    uniform_int_distribution<int>dist1(1,2);
    for(int i=0;i<T;i++){
        colors[i] = dist1(rng);
    }
    while(true){
        int tot = 0;
        for(int i=0;i<n;i++){
            int mx = choices[i].size(); //1 to size
            uniform_int_distribution<int>dist2(1,mx);
            team[i] = choices[i][dist2(rng)-1]; //teams are 0 based
            desig[i] = colors[team[i]];
        }
        for(int i=0;i<e;i++){
            int x = hate[i].ff;
            int y = hate[i].ss;
            if(desig[x]!=desig[y]){
                tot++;
            }
        }
        if(tot>=(e+1/2)){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout << team[i]+1 << " \n"[i==n-1];
    }
    for(int i=0;i<T;i++){
        cout << colors[i] << " \n"[i==T-1];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
