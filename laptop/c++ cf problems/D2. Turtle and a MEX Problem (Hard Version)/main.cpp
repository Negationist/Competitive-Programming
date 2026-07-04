#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int dfs(int cur, map<int,pii> &adj, map<int,int> &visited;){

}

void solve(){
    int n,m;
    cin >> n >> m;
    int mx = -1;
    multiset<int> fMex;
    map<int,int> b;
    for(int i=0;i<n;i++){
        int l;
        cin >> l;
        set<int> s;
        for(int j=0;j<l;j++){
            int a;
            cin >> a;
            s.insert(a);
        }
        int cur = 0;
        int first;
        for(int j=0;j<l+4;j++){
            if(s.find(j) == s.end() ){
                cur++;
                if(cur==1){
                    fMex.insert(j);
                    first = j;
                    mx = max(mx,j);
                } else if(cur==2){
                    b[first] = max(b[first],j); //make into set
                }
            }
        }
    }
    for(auto x : b){
        cout << "pair is: " << x.first << " " << x.second << "\n";
    }
    for(auto x : b){
        int c = x.first;
        int d = x.second;
        if(fMex.count(c)>1){
            mx = max(mx,d);
        }
    }
    int ans;
    if(mx >= m){
        ans = (m+1)*mx;
    } else{
       ans = (mx*mx) + (mx+m)*(m-mx+1)/2;
    }
    cout << "mx is " << mx << "\n";
    map<int,vii> adj;
    map<int,int> visited;
    for(auto x : b){
        int c = x.first;
        int d = x.second;
        adj[c].pb({d,d});
    }
    for(auto x : b){
        int c = x.first;
        int d = x.second;
        int taken = max(mx,c);
        int res = dfs(c,adj,visited);
        if(res>taken){
            ans+=res;
            ans-=taken;
        }
    }
    cout << "ans is " << ans << "\n";
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
