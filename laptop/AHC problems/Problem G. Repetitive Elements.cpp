#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)
#define sz(a) (int)(a.size())
#define all(a) (a.begin(), a.end())

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

vi mn_in;
set<int> mns;

struct RollbackUF{
    vi e;
    RollbackUF(int n): e(n, -1){}
    int size(int x) {return -e[find(x)];}
    int find(int x){ return e[x] < 0 ? x:  find(e[x]);}

    bool join(int a, int b){
        a = find(a), b = find(b);
        int mn1 = mn_in[a], mn2 = mn_in[b];
        if(a==b) return false;
        if(e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        mns.erase(max(mn1,mn2));
        mn_in[find(a)] = min(mn1,mn2);
        return true;
    }
};

const int inf = 1e8;

void solve(){
    int n; cin >> n;
    int N = 2*n-1;
    vi path(N);
    for(int i=0;i<N;i++){
        cin >> path[i];
    }
    mn_in.resize(n+10);
    mns.clear();
    for(int i=1;i<=n;i++){
        mn_in[i] = i;
        mns.insert(i);
    }
    path[0] = 1; path[N-1] = 1;
    vi dist(n+10, inf), par(n+10, inf);
    RollbackUF dsu(n+10); //nodes are one indexed
    vector<set<int>> adj(n+1, set<int>());
    int merges_left = n-1;
    int target = -1, t = 0, cur, ptr;
    for(int i=0;i<N-1;i++){
        if(path[i] && path[i+1]){
            if(dsu.join(path[i], path[i+1])){
                adj[path[i]].insert(path[i+1]);
                adj[path[i+1]].insert(path[i]);
                --merges_left;
            }
        }
        if(path[i] && !path[i+1]){
            cur = path[i];
            ptr = i+1;
        }
        t += (path[i] == 0);
        if(!path[i] && path[i+1]){
            target = path[i+1];
            dist[target] = 0;
            par[target] = inf;
        }
    }
    t++; //we get one more move to the target
    bool flag = 0;
    for(int i=0;i<N;i++){
        if(path[i] == 0){
            flag = 1;
        }
    }
    if(!flag){ //the path is done
        for(int x : path){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    //need to keep track of the min with the component that has one
    int mn_of_one = 1;
    while(dsu.find(1) ==  dsu.find(mn_of_one)){
        ++mn_of_one;
    }
    auto dfs = [&](auto self, int x, int p)->void {
        if(p != inf){
            par[x] = p;
            dist[x] = dist[p] + 1;
        }
        for(int y : adj[x]){
            if(y != p && dist[y] == inf){
                self(self, y, x);
            }
        }
    };
    dfs(dfs, target, inf);
    // for(int x : mns){
    //     cout << x << "!!\n";
    // }
    int old = -1;
    //cout << target << "!!!!!\n";
    while(t > 1){ //while we still have one more move to make
        //cout << t << "!\n";
        if(t == old) break;
        else old = t;
        vi moves;
        if(sz(adj[cur])) moves.pb(*adj[cur].begin()); //the move where we just go to a min neighbor
        if(par[cur] != inf) moves.pb(par[cur]); //the move where we need to go toward the target with a neighbor, "parent of this node"
        int inc = 0; //large number just to be safe
        for(int x : mns){
            if(inc++ > 4) break;
            moves.pb(x);
        } /*the move where we go to any component with something small that we would want to go to, if we are with target parity doesnt matter we can go to anything, 
        if we are not with target this move is definitely fine since we can always go to the target on last move assuming we didnt mess things up before*/
        moves.pb(target);
        if(sz(adj[target])) moves.pb(*adj[target].begin());
        //the move that we need to go to the target component, either go to the target or its minimum neighbor
        vi nmoves;
        for(int x : moves){
            if(x!=cur){
                nmoves.pb(x);
            }
        }
        moves = move(nmoves);
        sort(moves.begin(),moves.end()); //try smallest moves first
        for(int x : moves){
            //cout << "considering " << x << "!\n";
            bool to_target = (dsu.find(x) == dsu.find(target));
            if(to_target){ //assume by induction that the parity is ok
                int d = dist[x], time = t-1; //merges stay the same
                //cout << " d is " << d << ", time is " << time << ", new merges is " << merges_left << "\n";
                bool touching = (adj[x].find(cur) != adj[x].end());
                if((d <= time - 2 * merges_left) && touching){
                    path[ptr] = x;
                    merges_left-=dsu.join(x,cur);
                    cur = x;
                    ++ptr;
                    --t;
                    //cout << x << " was choosen\n";
                    break;
                }
            } else{
                int d = dist[cur]+1, time = t-1, new_merges = merges_left-1;
                //cout << " d is " << d << ", time is " << time << ", new merges is " << new_merges << "\n";
                if(d <= time - 2 * new_merges){
                    path[ptr] = x;
                    ++ptr;
                    adj[cur].insert(x);
                    adj[x].insert(cur);
                    dfs(dfs, x, cur);
                    merges_left-=dsu.join(x,cur);
                    cur = x;
                    --t;
                    //cout << x << " was choosen\n";
                    break;
                }
            }
        }
    }
    for(int x : path){
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