#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define tiii tuple<int,int,int>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    --n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sze = (1LL<<n);
    vector<vi> dp(sze,vi(101,0));
    map<pii,pii> trans;
    for(int i=1;i<=100;i++){
        dp[0][i] = 1;
    }
    for(int i=0;i<sze;i++){
        for(int j=1;j<=100;j++){
            bool flag = false;
            for(int k=0;k<n;k++){
                if(!flag && (i & (1LL<<k))){
                    if(a[k]%j==0 && a[k]/j<=100){
                        int last = a[k]/j;
                        int old = i-(1LL<<k);
                        if(dp[old][last]){
                            dp[i][j] = 1;
                            trans[{i,j}] = {old,last};
                            flag = true;
                        }
                    }
                }
            }
        }
    }
    vi ans;
    for(int i=1;i<=100;i++){
        if(dp[sze-1][i]){
            pii cur = {sze-1,i};
            pii bad = {0,0};
            while(cur!=bad){
                ans.pb(cur.ss);
                cur = trans[cur];
            }
            break;
        }
    }
    if(ans.size()){
        reverse(ans.begin(),ans.end());
        cout << "Yes\n";
        for(int x : ans){
            cout << x << " ";
        }
        cout << "\n";
    } else{
        cout << "No\n";
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
