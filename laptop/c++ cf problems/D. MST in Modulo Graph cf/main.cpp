#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

struct dsu{
    vector<int> parent;
    vector<int> cnt;
    dsu(int n){
        parent.resize(n);
        cnt.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int _find(int i){
        if(i!=parent[i]){
            parent[i] = _find(parent[i]);
        }
        return parent[i];
    }
    bool unite(int a, int b){
        int x = _find(a);
        int y = _find(b);
        if(x==y) return false;
        if(cnt[x]<cnt[y]){
            swap(x,y);
        }
        parent[y] = x;
        cnt[x]+=cnt[y];
        return true;
    }
};

void solve(){
    int n;
    cin >> n;
    vi p(n);
    int mx = 0;
    for(int i=0;i<n;i++){
        cin >> p[i];
        mx = max(mx,p[i]);
    }
    sort(p.begin(),p.end());
    vi real;
    for(int i=0;i<n;i++){
        if(!i || p[i]!=p[i-1]){
            real.pb(p[i]);
        }
    }
    p = real;
    n = real.size();
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<n;i++){
        int x = real[i];
        for(int j=1;j*x<=mx;j++){
            int pos = lower_bound(real.begin(),real.end(),j*x+(j==1))-real.begin();
            if(pos<n){
                edges.pb({real[pos]%x,i,pos});
            }
        }
    }
    sort(edges.begin(),edges.end());
    dsu tree(n);
    int ans = 0;
    for(auto [a,b,c] : edges){
        if(tree.unite(b,c)){
            ans+=a;
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
