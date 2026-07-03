#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    set<int> s;
    vector<set<int>> bucket(5);
    for(int i=0;i<n;i++){
        string x,y;
        cin >> x >> y;
        if(x=="unset" && y=="false"){
            a[i] = 0;
            s.insert(i);
        }
        else if (x=="set" && y=="true"){
             a[i] = 1;
             bucket[1].insert(i);
        }
        else if (x=="set" && y=="false"){
            a[i] = 2;
            bucket[2].insert(i);
        }
        else if (x=="unset" && y=="true"){
            a[i] = 3;
            bucket[3].insert(i);
        }
    }
    int q;
    cin >> q;
    vector<vi> adj(n);
    vector<vi> adj2(n);
    bool win = true;
    while(q--){
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        if(a[x] && a[y] && a[x]>a[y]){
            win = false;
        } else if(a[x]==a[y]){
            adj[y].pb(x);
            adj2[x].pb(y);
        }
        if(!a[x] && a[y]){
            if(bucket[4].find(x)==bucket[4].end()){
                bucket[0].insert(x);
                s.erase(x);
            } else{
                win = false;
            }
        } else if(a[x] && !a[y]){
            if(bucket[0].find(y)==bucket[0].end()){
                bucket[4].insert(y);
                s.erase(y);
            } else{
                win = false;
            }
        }
    }
    vector<int> ans;
    vector<bool> visited(n,false);
    auto dfs = [&](auto self, int cur)->void{
        s.erase(cur);
        visited[cur] = true;
        for(auto x : adj[cur]){
            if(visited[x]==false){
                self(self, x);
            }
        }
        ans.pb(cur);
        for(int x : adj2[cur]){
            if(visited[x]==false){
                self(self, x);
            }
        }
    };
    for(int i=0;i<5;i++){
        for(int x : bucket[i]){
            if(visited[x]==false){
                dfs(dfs,x);
            }
        }
    }
    auto temp = ans;
    ans.clear();
    for(int x : s){
        if(visited[x]==false){
            dfs(dfs,x);
        }
    }
    for(int x : temp){
        ans.pb(x);
    }
    int inc = 0;
    for(int x : ans){
        if(inc==0){
            if(a[x]==0) continue;
            else if(a[x]==1) inc++;
            else{
                win = false;
                break;
            }
        } else if(inc == 1){
            if(a[x]==2) continue;
            else if(a[x]==3) inc++;
            else{
                win = false;
                break;
            }
        } else if(inc == 2){
            if(a[x]){
                win = false;
                break;
            }
        }
    }
    if(win){
        for(int x : ans){
            cout << x+1 << " ";
        }
    } else{
        cout << -1;
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
