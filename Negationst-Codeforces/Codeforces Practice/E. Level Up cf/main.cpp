#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<vii> segs(n+5,vii());
    int maybe = 2*sqrt(n);
    int cap = min(maybe,n);
    for(int i=1;i<=cap;i++){
        int level = 1;
        int cnt = 0;
        segs[i].pb({0,level});
        for(int j=1;j<=n;j++){
            if(level<=a[j]){
                ++cnt;
            }
            if(cnt==i){
                cnt = 0;
                ++level;
                segs[i].pb({j+1,level});
            }
        }
    }
    int mx = n/cap;
    vector<vi> pref(n+1, vi(mx+20,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<mx+20;j++){
            pref[i][j] = pref[i-1][j]+(a[i]<=j);
        }
    }
    for(int i=cap+1;i<=n;i++){
        int level = 1;
        segs[i].pb({0,level});
        int pos = 1;
        int l = pos, r=n;
        bool good = false;
        while(l<=r){
            int mid = l+(r-l)/2;
            int gone = pref[mid][level-1];
            if(pos) gone-=pref[pos-1][level-1];
            int num = (mid-pos+1)-gone;
            if(num>=i){
                good = true;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        if(!good) continue;
        ++level;
        segs[i].pb({l+1,level});
        pos = l+1;
        if(pos>=n+1) break;
    }
    while(q--){
        int i,x;
        cin >> i >> x;
        int l = 0, r = segs[x].size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int num = segs[x][mid].ff;
            if(i>=num){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        int cur = segs[x][r].ss;
        if(a[i]>=cur){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
