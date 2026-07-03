#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n],dp[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        dp[n-1] = arr[n-1];
        int ans = arr[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i] = max(arr[i],dp[i+1]+1);
            ans = max(ans,dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
