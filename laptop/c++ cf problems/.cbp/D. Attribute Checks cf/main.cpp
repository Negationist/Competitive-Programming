#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void update(vector<int> &dp, vi &psum){
    int sum = 0;
    for(int i=0;i<psum.size();i++){
        sum+=psum[i];
        dp[i]+=sum;
        psum[i] = 0;
    }
}

void prop(vector<int> &dp){
    for(int i=dp.size()-1;i>0;i--){
        dp[i] = max(dp[i-1], dp[i]);
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> dp(m+1, 0);
    vi psum(m+1,0);
    int mtot = 0;
    for(int i=0;i<n;i++){
        if(!a[i]){
            update(dp, psum);
            prop(dp);
            mtot++;
        } else if(a[i]>0 && abs(a[i])<=mtot){
            psum[a[i]]++;
            if(mtot+1==m+1) continue;
            psum[mtot+1]--;
        } else if(abs(a[i]) <= mtot){
            psum[0]++;
            psum[mtot+a[i]+1]--;
        }
    }
    update(dp, psum);
    int mx = -1;
    for(int i=0;i<m+1;i++){
        mx = max(mx, dp[i]);
    }
    cout << mx << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
