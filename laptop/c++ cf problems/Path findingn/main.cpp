#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<int> path;
int pathCount;
bool searched[2000] = {};
void dfs(int a, int b, vector<vector<int>> vec){
    if(searched[a]) return;
    path.pb(a);
    searched[a] = true;
    if(a==b){
        pathCount++;
        cout << "path " << pathCount << " is: ";
        for(int node : path){
            cout << char(node+'A') << " ";
        }
        searched[a] = false;
        path.pop_back();
        cout << "\n";
        return;
    }
    for(int x : vec[a]){
        dfs(x,b,vec);
    }
    searched[a] = false;
    path.pop_back();
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cout << "how many vertices?\n";
    int n;
    cin >> n;
    cout << "enumerate\n";
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        for(int j=0;j<x;j++){
            char c;
            cin >> c;
            int convert = c-'A';
            graph[i].pb(convert);
        }
    }
    char a,b;
    cin >> a >> b;
    int node1 = a-'A';
    int node2 = b-'A';
    dfs(node1,node2,graph);
    return 0;
}
