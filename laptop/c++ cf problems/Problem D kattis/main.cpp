#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

bool check(vector<string> &graph,int i, int j, char want){
    int good = false;
    int h = graph.size();
    int w = graph[0].size();
    if(i-1>=0){
        if(graph[i-1][j]==want){
            good = true;
        }
    }
    cout << "1\n";
    if(i+1<w){
        if(graph[i-1][j]==want){
            good = true;
        }
    }
    cout << "2\n";
    if(j-1>=0){
        if(graph[i][j-1]==want){
            good = true;
        }
    }
    cout << "3\n";
    if(j+1<h){
        if(graph[i][j+1]==want){
            good = true;
        }
    }
    cout << "4\n";
    return good;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> graph(n);
    for(int i=0;i<n;i++){
        cin >> graph[i];
    }
    //find outer ring
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cout << "ran\n";
            if(graph[i][j]!='T') continue;
            bool res = check(graph,i,j,'.');
            if(res){
                graph[i][j] = '1';
            }
        }
    }
    cout << "outer ring\n";
    //find others
    int cur = 2;
    while(true){
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool res = check(graph,i,j, to_string(cur-1)[0]);
                if(res){
                    found = true;
                    graph[i][j] = to_string(cur)[0];
                }
            }
        }
        if(!found) break;
        cur++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << graph[i][j];
        }
        cout << "\n";
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
