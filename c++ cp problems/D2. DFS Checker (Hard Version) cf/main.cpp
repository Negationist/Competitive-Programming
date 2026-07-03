#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int num;
void solve(){
    int n,q;
    cin >> n >> q;
    vi fa(n);
    vector<set<int>> sons(n);
    for(int i=1;i<n;i++){
        cin >> fa[i];
        --fa[i];
        sons[fa[i]].insert(i);
    }
    vi siz(n,1);
    for(int i=n-1;i>=1;i--){
        siz[fa[i]]+=siz[i];
    }
    vi p(n);
    vi pos(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    auto check = [&](int x)->int{
         if(x==0){
            if(pos[x]==0){
                return 1;
            } else{
                return 0;
            }
        } else if(sons[x].size()==0){
            return 1;
        } else{
            bool good1 = pos[x] < pos[*sons[x].begin()];
            bool good2 = pos[x]+siz[x] >= pos[*sons[x].rbegin()]+siz[*sons[x].rbegin()];
            return (good1 && good2);
        }
    };
    num = 0;
    for(int i=0;i<n;i++){
        num+=check(i);
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        --x;--y;
        set<int> cur;
        cur.insert(p[x]);
        cur.insert(p[y]);
        if(p[x]) cur.insert(fa[p[x]]);
        if(p[y]) cur.insert(fa[p[y]]);
        for(int x : cur){
            num-=check(x);
        }
        swap(pos[p[x]],pos[p[y]]);
        swap(p[x],p[y]);
        for(int x : cur){
            num+=check(x);
        }
        if(num==n){
            cout << "yes\n";
        } else{
            cout << "no\n";
        }
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
