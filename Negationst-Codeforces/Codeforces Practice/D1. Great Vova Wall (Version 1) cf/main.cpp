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
    int n;
    cin >> n;
    vi a(n);
    int odd = 0, even = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]%=2;
        odd+=(a[i]);
        even+=(!(a[i]));
    }
    bool win = false;
    if(odd%2==0){
        auto temp = a;
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1] && a[i]==1){
                a[i] = 0;
                a[i+1] = 0;
            }
        }
        vi pos;
        for(int i=0;i<n;i++){
            if(a[i]){
                pos.pb(i);
            }
        }
        int z = pos.size();
        vii adj(z,{-1,-1});
        set<pii> good;
        for(int i=0;i<z;i++){
            if(i>0){
                adj[i].ff = i-1;
                int diff = pos[i]-pos[i-1];
                if(diff%2==1){
                    good.insert({i-1,i});
                }
            }
            if(i<z-1){
                adj[i].ss = i+1;
                int diff = pos[i+1]-pos[i];
                if(diff%2==1){
                    good.insert({i,i+1});
                }
            }
        }
        int cnt = z;
        vector<int> seen(z,0);
        while(cnt && good.size()){
            int x = good.begin()->first;
            int y = good.begin()->second;
            good.erase({x,y});
            if(seen[x] || seen[y]){
                continue;
            }
            seen[x] = 1;
            seen[y] = 1;
            cnt-=2;
            if(cnt==0) break;
            int l = adj[x].ff;
            int r = adj[y].ss;
            if(l!=-1 && r!=-1){
                adj[l].ss = r;
                adj[r].ff = l;
                int diff = pos[r]-pos[l];
                if(diff%2==1){
                    good.insert({l,r});
                }
            }else if(l!=-1){
                adj[l].ss = r;
            } else if(r!=-1){
                adj[r].ff = l;
            }
        }
        if(cnt==0){
            win = true;
        }
        a = temp;
    }
    if(even%2==0){
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1] && a[i]==0){
                a[i] = 1;
                a[i+1] = 1;
            }
        }
        vi pos;
        for(int i=0;i<n;i++){
            if(!a[i]){
                pos.pb(i);
            }
        }
        int z = pos.size();
        vii adj(z,{-1,-1});
        set<pii> good;
        for(int i=0;i<z;i++){
            if(i>0){
                adj[i].ff = i-1;
                int diff = pos[i]-pos[i-1];
                if(diff%2==1){
                    good.insert({i-1,i});
                }
            }
            if(i<z-1){
                adj[i].ss = i+1;
                int diff = pos[i+1]-pos[i];
                if(diff%2==1){
                    good.insert({i,i+1});
                }
            }
        }
        int cnt = z;
        vector<int> seen(z,0);
        while(cnt && good.size()){
            int x = good.begin()->first;
            int y = good.begin()->second;
            good.erase({x,y});
            if(seen[x] || seen[y]){
                continue;
            }
            seen[x] = 1;
            seen[y] = 1;
            cnt-=2;
            if(cnt==0) break;
            int l = adj[x].ff;
            int r = adj[y].ss;
            if(l!=-1 && r!=-1){
                adj[l].ss = r;
                adj[r].ff = l;
                int diff = pos[r]-pos[l];
                if(diff%2==1){
                    good.insert({l,r});
                }
            }else if(l!=-1){
                adj[l].ss = r;
            } else if(r!=-1){
                adj[r].ff = l;
            }
        }
        if(cnt==0){
            win = true;
        }
    }
    if(win){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
