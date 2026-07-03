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
    int n,m,p;
    cin >> n >> m >> p;
    vii j(n);
    vii r(m);
    vii s(p);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        j[i] = {a,b};
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        r[i] = {a,b};
    }
    for(int i=0;i<p;i++){
        int a,b;
        cin >> a >> b;
        s[i] = {a,b};
    }
    long double ans = 0;
    priority_queue<tuple<int,int,int>>q;
    for(int i=0;i<n;i++){
        for(int l=0;l<m;l++){
            int x = j[i].ff - r[l].ff;
            int y = j[i].ss - r[l].ss;
            int dist = x*x+y*y;
            q.push({-dist,-i,-l});
        }
    }
    vector<bool> visited1(n,false);
    vector<bool> visited2(m,false);
    while(q.size()){
        long double x = get<0>(q.top()), y = get<1>(q.top()), z=get<2>(q.top());
        x*=-1;
        y*=-1;
        z*=-1;
        q.pop();
        if(visited1[y]||visited2[z]) continue;
        visited1[y] = true;
        visited2[z]  =true;
        ans+=(sqrt(x));
    }
    for(int i=0;i<n;i++){
        for(int l=0;l<p;l++){
            int x = j[i].ff - s[l].ff;
            int y = j[i].ss - s[l].ss;
            int dist = x*x+y*y;
            q.push({-dist,-i,-l});
        }
    }
    visited1.assign(n,false);
    visited2.assign(p,false);
    while(q.size()){
        long double x = get<0>(q.top()), y = get<1>(q.top()),z=get<2>(q.top());
        x*=-1;
        y*=-1;
        z*=-1;
        q.pop();
        if(visited1[y]||visited2[z]) continue;
        visited2[z] = true;
        visited1[y] = true;
        ans+=(sqrt(x));
    }
    cout << fixed << setprecision(15) << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
