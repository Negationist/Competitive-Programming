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
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    string narek = "narek";
    set<char> name;
    for(char x : narek) name.insert(x);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    vector<vi> dp(2,vi(5,0));
    int z = 0;
    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            int tot = 0;
            int cur = j;
            for(int k=0;k<m;k++){
                if(s[i][k]==narek[cur]){
                    cur = (cur+1)%5;
                    tot++;
                } else if(name.find(s[i][k])!=name.end()){
                    tot--;
                }
            }
            dp[1-z][cur] = max(dp[1-z][cur], dp[z][j]+tot);
        }
        for(int i=0;i<5;i++){
            dp[1-z][i] = max(dp[1-z][i],dp[z][i]);
            mx = max(mx, dp[1-z][i] - i);
        }
        z = 1-z;
    }
    cout << mx << "\n";
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
