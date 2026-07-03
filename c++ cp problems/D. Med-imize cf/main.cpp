#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;
const int N = 500002;
int a[N],b[N],dp[N],n,k;

bool check(int med){
    for(int i=0;i<n;i++){
        if (a[i] >= med){
            b[i] = 1;
        } else{
            b[i] = -1;
        }
    }
    dp[0] = b[0];
    for(int i=0;i<n;i++){
        if (i%k==0){
            dp[i] = max(b[i],dp[i-k]);
        }
        else{
            dp[i] = max(dp[i-1]+b[i],dp[i-k]);
        }
    }
    return dp[n-1] > 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int lo = 1, hi = 1e9;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            if (check(mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return 0;
}
