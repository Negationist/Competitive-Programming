#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    map<pii,int> index;
    int cnt = 0;
    auto rev = [&](pii &a)->pii{
        return {a.ss,a.ff};
    };
    vii p(n+1);
    for(int i=1;i<=n;i++){
        p[i] = {a[i],b[i]};
        index[p[i]] = i;
        if(a[i]==b[i]) ++cnt;
    }
    for(int i=1;i<=n;i++){
        if(!index[rev(p[i])]){
            cout << -1 << "\n";
            return;
        }
    }
    if(cnt>1){
        cout << -1 << "\n";
        return;
    }
    vii out;
    for(int i=1;i<=n;i++){
        if(p[i]==rev(p[i]) || index[p[i]]+index[p[i]]==n+1) continue;
        if(index[p[i]]+index[rev(p[i])]!=n+1){
            int x = n+1-index[p[i]];
            int y = index[rev(p[i])];
            out.pb({x,y});
            index[p[y]] = x;
            index[p[x]] = y;
            swap(p[x],p[y]);
        }
    }
    cout << out.size() << "\n";
    for(int i=0;i<out.size();i++){
        cout << out[i].ff << " " << out[i].ss << "\n";
    }
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
