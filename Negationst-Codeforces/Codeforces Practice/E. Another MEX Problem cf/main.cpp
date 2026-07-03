#include <bits/stdc++.h>
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
    vector<vi> segs(n+1,vi());
    vi a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int l=1;l<=n;l++){
        int mex = 0;
        vector<int> cnt(5005,0);
        for(int r=l;r<=n;r++){
            ++cnt[a[r]];
            while(cnt[mex]) mex++;
            if(a[l]<=mex && a[r]<=mex){
                if(cnt[a[l]]==1 && cnt[a[r]]==1){
                    segs[r].pb(l);
                }
            }
        }
    }
    vector<vi> dp(n+1,vi(8194,0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        if(segs[i].size()==0) continue;
        int k = segs[i].size()-1;
        int mex = 0;
        vector<int> cnt(5005,0);
        for(int j=i;j>=0;j--){
            cnt[a[j]]++;
            while(cnt[mex]) ++mex;
            if(j==segs[i][k]){
                for(int z=0;z<8194;z++){
                    if(!dp[j-1][z]) continue;
                    else{
                        int res = z^mex;
                        dp[i][res] = 1;
                    }
                }
                k--;
            }
            if(k<0) break;
        }
    }
    for(int i=8193;i>=0;i--){
        if(dp[n][i]){
            cout << i << "\n";
            return;
        }
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
