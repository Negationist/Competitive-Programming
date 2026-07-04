#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<int> memo;
set<int> s;
string colors;
unordered_map<int,int> pos;
vector<int> b;
int dfs(int x, int sum){
    int position = pos[x];
    s.erase(x);
    int next = b[x];
    if(s.find(next) ==  s.end()){
        return 0;
    } else{
        if(colors[position]=='0'){
            memo[x] = dfs(next, sum+1);
        } else{
            memo[x] = dfs(next, sum);
        }
    }
}

void solve(){
    s.clear();
    pos.clear();
    int n;
    cin >> n;
    b.resize(n);
    memo.resize(n);
    for(int i=0;i<n;i++){
        memo[i] = -1;
        s.insert(i);
    }
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        b[i] = z-1;
        pos[z-1]=i;
    }
    cin >> colors;
    while(!s.empty()){
        dfs(*s.begin(),0);
    }
    for(int i=0;i<n;i++){
        cout << memo[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
