#include <bits/stdc++.h>
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
const int inf = 1LL<<19;

// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};
const int maxN = 5002;
int dp[maxN][maxN];
void solve(){
    int r,c,n;
    cin >> r >> c >> n;
    vector<pii> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i].ff >> p[i].ss;
    }
    p.pb({-1e7,-1e7});
    sort(p.begin(),p.end(),
         [&](const pii &i, const pii &j){
                if(i.ff!=j.ff){
                    return i.ff<j.ff;
                }
                return i.ss<j.ss;
            }
         );

    unordered_map<pii,int,pair_hash> m;
    for(int i=1;i<=n;i++){
        m[p[i]] = i;
    }
    int ans = -1;
    auto out_of_grid = [&](pii &x){
        return (x.ff<1 || x.ff>r || x.ss>c || x.ss<1);
    };
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            pii delta = {p[j].ff-p[i].ff,p[j].ss-p[i].ss};
            pii q = {p[j].ff+delta.ff,p[j].ss+delta.ss};
            int index = m[q];
            if(m[q]){
                dp[i][j] = dp[j][index]+1;
            } else{
                if(out_of_grid(q)){
                    dp[i][j] = 2;
                } else{
                    dp[i][j] = -inf;
                }
            }
            pii before = {p[i].ff-delta.ff,p[i].ss-delta.ss};
            if(out_of_grid(before)){
                ans = max(dp[i][j],ans);
            }
        }
    }
    cout << (ans>=3?ans:0) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
