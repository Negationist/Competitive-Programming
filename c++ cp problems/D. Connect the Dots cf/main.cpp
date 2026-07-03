#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

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
    int n,m;
    cin >> n >> m;
    dsu a(n);
    const int mx = 11;
    int ans = n;
    vector l(mx, vector(mx, vector<pii>()));
    while(m--){
        int a,d,k;
        cin >> a >> d >> k;
        a--;
        if(k<=0) continue;
        l[d][a%d].pb({a/d, a/d+k-1});
    }
    for(int i=1;i<mx;i++){
        for(int j=0;j<i;j++){
            auto &v = l[i][j];
            sort(v.begin(),v.end());
            int last = -1;
            for(auto &[x,y] : v){
                for(int z=max(last+1,x);z<=y;z++){
                    ans-=a.unite(j+z*i, j+(z+1)*i);
                }
                last = max(last, y);
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
