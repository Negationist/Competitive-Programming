#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >> n;
        vector<int> a(n);
        vector<int> dp(n);
        for(int &x : a){
            cin >> x;
        }
        for(int i=n-1;i>=0;i--){
            dp[i] = a[i];
            int next  = i+a[i];
            if(next < n){
                dp[i]+= dp[next];
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
