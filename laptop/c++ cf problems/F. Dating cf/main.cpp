#include <bits/stdc++.h>
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
    int n,m;
    cin >> n >> m;
    vector<set<int>> a(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        for(int j=0;j<z;j++){
            int temp; cin >> temp;
            a[i].insert(temp);
        }
    }
    vi p(n);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),
         [&](int i, int j){
            return a[i].size() > a[j].size();
         }
         );
    auto is_sub = [&](int x, int y){
        for(int z : a[x]){
            if(a[y].find(z) == a[y].end()){
                return false;
            }
        }
        return true;
    };
    vi pointer(m+1,-1);
    for(int i=0;i<n;i++){
        int cur = p[i];
        if(a[cur].size()==0) continue;
        int z = -1;
        int mn = INT_MAX;
        for(int x : a[cur]){
            int pnt = pointer[x];
            if(pnt==-1) continue;
            else if(a[pnt].size()<mn){
                mn = a[pnt].size();
                z = x;
            }
        }
        if(z==-1){
            for(int thing : a[cur]){
                pointer[thing] = cur;
            }
        } else{
            if(is_sub(cur,pointer[z])){
                for(int thing : a[cur]){
                    pointer[thing] = cur;
                }
            } else{
                cout << "YES\n" << cur+1 << " " << pointer[z]+1 << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
