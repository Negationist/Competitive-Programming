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
int n,m;
int dfs(int i, int j, set<pii> &visited, map<pii,int> &what, vector<string> &s){
    visited.erase({i,j});
    if(s[i][j]=='?'){
        return 1;
    } else if(s[i][j]=='U'){
        if(i==0){
            what[{i,j}] = 0;
            return 0;
        } else{
            if(visited.find({i-1,j}) == visited.end()){
                if(what[{i-1,j}]==2){
                    what[{i,j}] = 1;
                    return 1;
                } else{
                    what[{i,j}] = what[{i-1,j}];
                    return what[{i-1,j}];
                }
            }
            int res = dfs(i-1,j,visited,what,s);
            what[{i,j}]= res;
            return res;
        }
    } else if(s[i][j]=='D'){
        if(i==n-1){
            what[{i,j}] = 0;
            return 0;
        } else{
            if(visited.find({i+1,j}) == visited.end()){
                if(what[{i+1,j}]==2){
                    what[{i,j}] = 1;
                    return 1;
                } else{
                    what[{i,j}] = what[{i+1,j}];
                    return what[{i+1,j}];
                }
            }
            int res = dfs(i+1,j,visited,what,s);
            what[{i,j}]= res;
            return res;

        }
    }
    else if(s[i][j]=='L'){
        if(j==0){
            what[{i,j}] = 0;
            return 0;
        } else{
            if(visited.find({i,j-1}) == visited.end()){
                if(what[{i,j-1}]==2){
                    what[{i,j}] = 1;
                    return 1;
                } else{
                    what[{i,j}] = what[{i,j-1}];
                    return what[{i,j-1}];
                }
            }
            int res = dfs(i,j-1,visited,what,s);
            what[{i,j}]= res;
            return res;
        }
    }
    else if(s[i][j]=='R'){
        if(j==m-1){
            what[{i,j}] = 0;
            return 0;
        } else{
            if(visited.find({i,j+1}) == visited.end()){
                if(what[{i,j+1}]==2){
                    what[{i,j}] = 1;
                    return 1;
                } else{
                    what[{i,j}] = what[{i,j+1}];
                    return what[{i,j+1}];
                }
            }
            int res = dfs(i,j+1,visited,what,s);
            what[{i,j}]= res;
            return res;
        }
    }
}

void solve(){
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    map<pii,int> what;
    set<pii> visited;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited.insert({i,j});
            what[{i,j}]= 2;
        }
    }
    while(visited.size()){
        int x = (visited.begin())->ff;
        int y = (visited.begin())->ss;
        dfs(x,y,visited,what,s);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(what[{i,j}]==1){
                ans++;
            } else if(what[{i,j}]==2){
                if(i!=0){
                    if(what[{i-1,j}]==1 || s[i-1][j]=='?'){
                        ans++;
                        continue;
                    }
                }
                if(i!=n-1){
                    if(what[{i+1,j}]==1 || s[i+1][j]=='?'){
                        ans++;
                        continue;
                    }
                }
                if(j!=0){
                    if(what[{i,j-1}]==1 || s[i][j-1]=='?'){
                        ans++;
                        continue;
                    }
                }
                if(j!=m-1){
                    if(what[{i,j+1}]==1 || s[i][j+1]=='?'){
                        ans++;
                        continue;
                    }
                }
            }
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
