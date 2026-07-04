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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vi col(m,0);
    vi row(n,0);
    vector<vi> ans(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int z;
            cin >> z;
            row[i]+=z;
            col[j]+=z;
            ans[i][j] = z;
        }
    }
    int target = 0;
    //for(int i=0;i<14;i++) target*=10;
    int x=0,y=0;
    int cur = 0;
    while(x!=m-1 || y!=n-1){
        if(s[cur]=='D'){
            int diff = target-row[y];
            ans[y][x] = diff;
            row[y]+=diff;
            col[x]+=diff;
            y++;
        } else{
            int diff = target-col[x];
            ans[y][x] = diff;
            row[y]+=diff;
            col[x]+=diff;
            x++;
        }
        ++cur;
    }
    int diff = target-row[y];
    ans[y][x] = diff;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
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
