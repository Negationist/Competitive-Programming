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
    int n; cin >> n;
    vector<vi> adj(n,vi());
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    priority_queue<pii> q0, q1;
    auto dfs = [&](auto self, int x, int p, int d){
        if(x!=n-1 && d%2===0){
            q0.push({d,x});
        } else if(x!=n-1 && d%2==1){
            q1.push({d,x});
        }
        for(int y : adj[x]){
            if(y!=p){
                self(self, y, x, d+1);
            }
        }
    };
    vector<string> out;
    bool last = 0, p = 0; //we deleted last time
    while(!q0.empty() || !q1.empty()){
        if(last){
            out.pb("1");
            p = 1-p;
        } else if(p==0 && q0.empty()){
            out.pb("1");
            p = 1-p;
        }else if(p==1 && q1.empty()){
            out.pb("1");
            p = 1-p;
        } else{
            if(p==0){
                int cur = q0.top().ss;
                q0.pop();
                out.pb("2");
                out.pb((string)cur+1);
            } else{
                int cur = q1.top().ss;
                q0.pop();
                out.pb("2");
                out.pb((string)cur+1);
            }
        }
    }
    for(string x : out){
        cout << x << " ";
    }
    cout << "\n";
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