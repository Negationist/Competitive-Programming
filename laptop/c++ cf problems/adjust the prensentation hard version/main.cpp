#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int inf = 1LL<<60;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        int z;
        cin >> z;
        a[z] = i;
    }
    vector<int> dp(n+1, inf);
    map<int,set<int>> pos;
    vi cnt(n+1, 0);
    set<int> seen;
    vi num(n+1, 0);
    vi b(n+1);
    for(int i=1;i<=m;i++){
        int z;
        cin >> z;
        b[i] = z;
        int x = a[z];
        dp[x] = min(dp[x],i);
        pos[x].insert(i);
        seen.insert(x);
        num[x]++;
    }
    set<int> bad;
    bad.insert(inf);
    int mn;
    for(int i=1;i<=n;i++){
        if(i>1){
            if(dp[i]<dp[i-1]){
                cnt[i]++; bad.insert(i);
                cnt[i-1]++; bad.insert(i-1);
            }
        }
        if(i<n){
            if(dp[i]>dp[i+1]){
                cnt[i]++; bad.insert(i);
                cnt[i+1]++; bad.insert(i+1);
            }
        }
        mn = *bad.begin();
    }
    if(mn>seen.size()){
        cout << "ya\n";
    } else{
        cout << "TIDAK\n";
    }
    while(q--){
        int x,y;
        cin >> x >> y;

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
