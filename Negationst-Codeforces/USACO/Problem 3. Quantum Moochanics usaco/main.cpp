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
    vi p(n),s(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    auto time = [&](int a, int b)->int{
        bool toward = (a%2==0);
        int dis = p[b]-p[a];
        int speed = s[b]+s[a];
        int res = (dis+speed-1)/speed;
        res = 2*res-toward;
        return res;
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vii next(n);
    for(int i=0;i<n;i++){
        if(i>0){
            next[i].ff = i-1;
            pq.push({time(i-1,i),i-1,i});
        } else{
            next[i].ff = -1;
        }
        if(i<n-1){
            next[i].ss = i+1;
            pq.push({time(i,i+1),i,i+1});
        } else{
            next[i].ss = -1;
        }
    }
    vi ans(n,0);
    while(pq.size()){
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        int z = get<0>(pq.top());
        pq.pop();
        if(ans[x] || ans[y]){
            continue;
        }
        ans[x] = ans[y] = z;
        int l = next[x].ff;
        int r = next[y].ss;
        if(l!=-1 && r!=-1){
            next[l].ss = r;
            next[r].ff = l;
            pq.push({time(l,r),l,r});
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i];
        if(i!=n-1){
            cout << " ";
        }
    }
    cout << "\n";
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
