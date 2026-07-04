#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define tii tuple<int,int,int>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<tii> events;
    for(int i=1;i<=n;i++){
        int d,a;
        cin >> d >> a;
        events.pb({d,i,a});
        events.pb({d+k,-i,-1});
    }
    vi milk(n+5,0);
    sort(events.begin(),events.end());
    int last = -1;
    int ans = 0;
    set<int> avail;
    for(auto [x,y,z] : events){
        int num = abs(y);
        if(last!=-1){
            int len = x-last-1;
            if(len<=0) break;
            int amount = len*m;
            vi trash;
            for(int u : avail){
                int cur = -u;
                int len = x-last-1;
                int amount = len*m;
                if(milk[cur]>=amount){
                    milk[cur]-=amount;
                    amount = 0;
                    break;
                } else{
                    amount-=milk[cur];
                    trash.pb(cur);
                }
            }
            for(int u : trash){
                avail.erase(u);
            }
            int res = (len*m-amount)/m;
            cout << "from day " << last+1 << " to day " << x-1 << "we got " << res << "\n";
            ans+=res;
        }
        if(y>0){
            milk[num] = z;
            avail.insert(-num);
        } else{
            avail.erase(num);
        }
        if(last!=x && get<0>(events)){
            int res = m;
            vi trash;
            for(int u : avail){
                int cur = -u;
                if(milk[u]>=res){
                    milk[u]-=res;
                    res = 0;
                    break;
                } else{
                    res-=milk[u];
                    trash.pb(u);
                }
            }
            for(int u : trash){
                avail.erase(u);
            }
            if(!res){
                ++ans;
                cout << "on day " << x << " we got " << "1\n";
            }
            last = x;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
