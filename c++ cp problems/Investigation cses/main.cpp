#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define tii tuple<int,int,int,int,int>

using namespace std;
const int inf = 1LL<<60;
const int mod = 1e9+7;

void print(tii temp){
    cout << get<0>(temp) << " " << get<1>(temp) << " " << get<2>(temp) << " " << get<3>(temp);
    cout << " " << get<4>(temp)+1 << "\n";
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vii> adj(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a].pb({b,c});
    }
    auto cmp = [](tii a, tii b) {
        return a > b;
    };
    priority_queue<tii, vector<tii>, decltype(cmp)> pq(cmp);
    vi mx(n,-inf),mn(n,inf); //flights mn and max
    vi distance(n,inf); //min distance
    vi cnt(n,0); //number of is in the queue
    vi ways(n,0); //number of ways to reach i with mn dist
    distance[0] = 0;
    mn[0] = 0;
    mx[0] = 0;
    for(auto x : adj[0]){
        tii cur = {x.ss,1,1,1,x.ff};
        distance[x.ff] = x.ss;
        cnt[x.ff] = 1;
        pq.push(cur);
    }
    vi done(n,0);
    while(pq.size()){
        tii cur = pq.top();
        pq.pop();
        //print(cur);
        int node = get<4>(cur);
        int cost = get<0>(cur);
        if(done[node]) continue;
        ways[node]+=get<1>(cur);
        ways[node]%=mod;
        mn[node] = min(mn[node],get<2>(cur));
        mx[node] = max(mx[node],get<3>(cur));
        --cnt[node];
        if(cnt[node]){
            continue;
        }
        //cout << "going!\n";
        done[node] = true;
        for(auto x : adj[node]){
            tii temp;
            int len = distance[node]+x.ss;
            //cout << "len to " << x.ff+1 << " is " << len << "\n";
            //cout << "distance " << x.ff+1 << " is " << distance[x.ff] << "\n";
            temp = {len,ways[node]%mod,mn[node]+1,mx[node]+1,x.ff};
            if(len<distance[x.ff]){
                distance[x.ff] = len;
                cnt[x.ff] = 1;
                pq.push(temp);
                //cout << "pushing: " ;
                //print(temp);
            } else if(len==distance[x.ff]){
                ++cnt[x.ff];
                pq.push(temp);
                //cout << "pushing: " ;
                //print(temp);
            }
        }
    }
    cout << distance[n-1] << " " << ways[n-1] << " " << mn[n-1] << " " << mx[n-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
