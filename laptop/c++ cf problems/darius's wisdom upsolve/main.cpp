#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vii ans;
    vector<set<int>> pos(3);
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[a[i]].insert(i);
    }
    auto b = a;
    sort(b.begin(),b.end());
    auto fix = [&](int i, int j, int k){
        int x = a[i];
        int y = a[j];
        int z = a[k];
        ans.pb({i,j});
        ans.pb({i,k});
        pos[x].erase(i);
        pos[y].erase(j);
        pos[z].erase(k);
        pos[x].insert(j);
        pos[y].insert(k);
        a[j] = x;
        a[i] = z;
        a[k] = y;
    };
    if(pos[0].size() <= pos[2].size()){
        while(pos[0].size()){
            int i = *pos[2].begin();
            int j = *pos[1].begin();
            int k = *pos[0].rbegin();
            if(b[k]==0){
                pos[0].erase(k);
            } else if(b[j]==0){
                pos[0].erase(k);
                pos[1].insert(k);
                swap(a[j],a[k]);
                ans.pb({j,k});
            }
            else fix(i,j,k);
        }
        int i=0,j=0;
        while(true){
            while(i<n && !(a[i]==2 && b[i]==1)) i++;
            if(i==n) break;
            while(j<n && !(a[j]==1 && b[j]==2)) j++;
            ans.pb({i,j});
            swap(a[i++],a[j++]);
        }
    } else{
        while(pos[2].size()){
            int i = *pos[0].rbegin();
            int j = *pos[1].begin();
            int k = *pos[2].begin();
            if(b[k]==2){
                pos[2].erase(k);
            } else if(b[j]==2){
                pos[2].erase(k);
                pos[1].insert(k);
                swap(a[j],a[k]);
                ans.pb({j,k});
            }
            else fix(i,j,k);
        }
        int i=0,j=0; //want to fix 1 and 2
        while(true){
            while(i<n && !(a[i]==0 && b[i]==1)) i++;
            if(i==n) break;
            while(j<n && !(a[j]==1 && b[j]==0)) j++;
            ans.pb({i,j});
            swap(a[i++],a[j++]);
        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x.ff+1 << " " << x.ss+1 << "\n";
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
