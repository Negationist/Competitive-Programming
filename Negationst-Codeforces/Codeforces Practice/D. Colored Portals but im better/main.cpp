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
    int n,q;
    cin >> n >> q;
    vii next(n,{-1,-1});
    stack<pair<string,int>> s;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int x = i;
        while(s.size()){
            int y = s.top().ss;
            if((a[x][0]==a[y][0] || a[x][0]==a[y][1] || a[x][1]==a[y][0] || a[x][1]==a[y][1]) && a[x]!=a[y]){
                next[y].ss = i;
                s.pop();
            } else break;
        }
        s.push({a[i],i});
    }
    while(s.size()) s.pop();
    for(int i=n-1;i>=0;i--){
        int x = i;
        while(s.size()){
            int y = s.top().ss;
            if((a[x][0]==a[y][0] || a[x][0]==a[y][1] || a[x][1]==a[y][0] || a[x][1]==a[y][1]) && a[x]!=a[y]){
                next[y].ff = i;
                s.pop();
            } else break;
        }
        s.push({a[i],i});
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        if(a[x][0]==a[y][0] || a[x][0]==a[y][1] || a[x][1]==a[y][0] || a[x][1]==a[y][1]){
            cout << abs(x-y) << "\n";
        } else{
            if(x<y){
                if(next[x].ss!=-1){
                    int z = next[x].ss;
                    int res = abs(x-z)+abs(z-y);
                    cout << res << "\n";
                } else{
                    if(next[x].ff==-1){
                        cout << -1 << "\n";
                    } else{
                        cout << abs(x-y)+2*abs(x-next[x].ff) << "\n";
                    }
                }
            } else{
                if(next[x].ff!=-1){
                    int z = next[x].ff;
                    int res = abs(x-z)+abs(z-y);
                    cout << res << "\n";
                } else{
                    if(next[x].ss==-1){
                        cout << -1 << "\n";
                    } else{
                        cout << abs(x-y)+2*abs(x-next[x].ss) << "\n";
                    }
                }
            }
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
