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
    int n;
    cin >> n;
    map<int,int> top, bottom;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        ++top[z];
    }
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        ++bottom[z];
    }
    int need = n - (top[-1]+bottom[-1]), mx = -1;
    if(need<=1){
        cout << "Yes\n";
        return;
    }
    top.erase(-1);
    bottom.erase(-1);
    vii top_pairs, bot_pairs;
    multiset<int> cands;
    for(auto x : top){
        top_pairs.pb({x.ff,x.ss});
        if(x.ss != bottom[x.ff]){
            mx = max(mx,x.ff);
        }
        int mn = min(x.ss, bottom[x.ff]);
        for(int i=0;i<mn;i++){
            cands.insert(x.ff);
        }
    }
    for(auto x : bottom){
        bot_pairs.pb({x.ff,x.ss});
        if(x.ss != top[x.ff]){
            mx = max(mx,x.ff);
        }
    }
    if(cands.size()){
        int have = 1, hi = *cands.rbegin();
        cands.erase(cands.find(hi));
        while(cands.size()){
            int next = *cands.rbegin();
            if(next+hi>=mx){
                ++have;
                cands.erase(cands.find(next));
            } else{
                break;
            }
        }
        if(have>=need){
            cout << "Yes\n";
            return;
        }
    }
    vi gone;
    for(auto [a,b] : bottom){
        if(b==0){
            gone.pb(a);
        }
    }
    for(int x : gone){
        bottom.erase(x);
    }
    gone.clear();
    for(auto [a,b] : top){
        if(b==0){
            gone.pb(a);
        }
    }
    for(int x : gone){
        top.erase(x);
    }
    for(auto [a,b] : bot_pairs){
        for(auto [c,d] : top_pairs){
            int cnt = min(b,d);
            top[a]-=cnt;
            bottom[c]-=cnt;
            if(top[a]==0){
                top.erase(a);
            }
            if(bottom[c]==0){
                bottom.erase(c);
            }
            mx = max(top.rbegin()->ff, bottom.rbegin()->ff);
            if(a+c>=mx && cnt>=need){
                cout << "Yes\n";
                return;
            }
            top[a]+=cnt;
            bottom[c]+=cnt;
        }
    }
    cout << "No\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
