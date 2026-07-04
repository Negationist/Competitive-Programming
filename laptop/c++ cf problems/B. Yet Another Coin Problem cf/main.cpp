#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<int> dp(31, 2e9);
vector<int> coins = {1,3,6,10,15};

void populate(){
    for(int i=1;i<=30;i++){
        for(int x : coins){
            if(i-x >= 0){
                dp[i] = min(dp[i], 1 + dp[i-x]);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 0;
    int t;
    cin >> t;
    populate();
    while(t--){
        int n;
        cin >> n;
        if(n<=30){
            cout << dp[n];
        } else{
            int take = n-30;
            take = take + (15 - take%15);
            int res = dp[n-take]+take/15;
            cout << res;
        }
        cout << "\n";
    }
    return 0;
}
