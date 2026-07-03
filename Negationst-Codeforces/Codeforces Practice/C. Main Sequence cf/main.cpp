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
    map<int,vi> pos;
    int inc = 1;
    vi x(n+1);
    vi dubs(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> x[i];
        pos[x[i]].pb(inc);
        ++inc;
        if(x[i]==x[i-1]){
            dubs[i] = 1;
        }
    }
    vi pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+dubs[i];
    }
    vi neg(n+1,0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int z;
        cin >> z;
        neg[z] = 1;
    }
    bool win = true;
    for(auto x : pos){
        auto& temp = x.ss;
        int sze = temp.size();
        if(sze%2==1){
            win = false;
            break;
        }
        int sum = 0;
        for(int i=0;i<sze;i++){
            int cur = temp[i];
            if(neg[cur]){
                --sum;
            } else{
                ++sum;
            }
            if(sum<0){
                win = false;
            }
        }
        if(win==false){
            break;
        } else{
            for(int i=sze-1;i>=0 && sum>0;i--){
                if(neg[temp[i]]) continue;
                int last;
                int cur = temp[i];
                int next;
                if(i!=sze-1){
                    last = temp[i+1];
                }
                if(i!=0){
                    next = temp[i-1];
                }
                if()
            }
        }
    }
    if(win){
        cout << "YES\n";
        for(int i=1;i<=n;i++){
            if(neg[i]){
                cout << -x[i] << " ";
            } else{
                cout << x[i] << " ";
            }
        }
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
