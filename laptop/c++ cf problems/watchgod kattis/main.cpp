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
    int sl,h; cin>>sl>>h;
    vii hatches(h);
    for(int i=0; i<h; i++) {
        cin>>hatches[i].first;
        cin>>hatches[i].second;
    }
    for(int x=1; x<sl; x++) {
        for(int y=1; y<sl; y++) {
            int sd = min(min(x,y),min(sl-x,sl-y))*min(min(x,y),min(sl-x,sl-y));
            bool flag = true;
            bool onhatch = false;
            for(int k=0; k<h; k++) {
                int dx = x-hatches[k].first;
                int dy = y-hatches[k].second;
                int dist = dx*dx+dy*dy;
                if(dist==0){
                    onhatch=true;
                    break;
                }
                if(dist>sd) {
                    flag = false;
                    break;
                }
            }
            if(onhatch) continue;
            if(flag) {
                cout<<x<<" "<<y<<endl;
                return;
            }
        }
    }
    cout<<"poodle"<<endl;
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
