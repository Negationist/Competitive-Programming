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
    int n,k;
    cin >> n >> k;
    vi p(n),d(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> d[i];
    int q;
    cin >> q;
    while(q--){
        int cur, dir = 1, t = 0, mark;
        cin >> cur;
        mark = lower_bound(p.begin(),p.end(),cur) - p.begin();
        vector<vi> visited(n,vi(3,0));
        bool out, flag;
        while(true){
            flag = false; //continue the process
            out = true; //im out
            for(int i=mark;i<n && i>=0;i+=dir){
                int time = t+abs(cur-p[i]);
                if(time%k == d[i]){
                    if(visited[i][dir+1]){
                        out = false;
                    } else{
                        flag = true;
                        visited[i][dir+1] = true;
                        dir*=-1;
                       mark = i+dir;
                        cur = p[i];
                        t = time;
                    }
                    break;
                }
            }
            if(!flag) break;
        }
        cout << (!out?"no":"yes") << "\n";
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
