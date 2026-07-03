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
    string s;
    cin >> s;
    map<pii,vi> pos;
    pii o = {0,0};
    vii forw(n),bck(n);
    for(int i=0;i<n;i++){
        o.ss+=(s[i]=='U');
        o.ss-=(s[i]=='D');
        o.ff+=(s[i]=='R');
        o.ff-=(s[i]=='L');
        pos[o].pb(i);
        forw[i] = o;
    }
    o = {0,0};
    map<pii,vi> pos2;
    for(int i=n-1;i>=0;i--){
        o.ss+=(s[i]=='U');
        o.ss-=(s[i]=='D');
        o.ff+=(s[i]=='R');
        o.ff-=(s[i]=='L');
        pos2[o].pb(i);
        bck[i] = o;
    }
    set<pii> fixed;
    while(q--){
        int x,y,l,r;
        cin >> x >> y >> l >> r;
        --l;
        --r;
        pii cur = {x,y};
        if(!x && !y){
            cout << "yes\n";
            continue;
        }
        if(pos[cur].size()){
            int mn = pos[cur][0];
            int mx = pos[cur].back();
            if(mn<l || mx>r){
                cout << "yes\n";
                continue;
            }
        }
        pii start;
        if(!l) start = {0,0};
        else start = forw[l-1];
        pii diff = {cur.ff - start.ff, cur.ss - start.ss};
        pii fstart;
        if(r==n-1) fstart = {0,0};
        else fstart = bck[r+1];
        pii goal = {fstart.ff+diff.ff, fstart.ss+diff.ss};
        if(fixed.find(goal)==fixed.end()){
            fixed.insert(goal);
            reverse(pos2[goal].begin(),pos2[goal].end());
        }
        if(!pos2[goal].size()){
            cout << "no\n";
        }
        else{
            int best = lower_bound(pos2[goal].begin(),pos2[goal].end(),l)-pos2[goal].begin();
            if(best==pos2[goal].size()){
                cout << "no\n";
            } else{
                int maybe = pos2[goal][best];
                if(maybe<=r){
                    cout << "yes\n";
                } else{
                    cout << "no\n";
                }
            }
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
