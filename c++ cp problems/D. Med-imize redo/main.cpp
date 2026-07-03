#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)
//thanks shayan
using namespace std;

const int N = 5000001;
int n,k;
int a[N],b[N],dp[N];

bool check(int med){
    for (int i=0;i<n;i++){
        if(a[i]>=med){
            b[i] = 1;
        }
        else{
            b[i] = -1;
        }
    }
    dp[0] = b[0];
    for(int i=1;i<n;i++){
        if(i%k==0){
            dp[i] = max(b[i],dp[i-k]);
        } else{
            dp[i] = dp[i-1]+b[i];
            if(i>k){
                dp[i] = max(dp[i],dp[i-k]);
            }
        }
    }
    return dp[n-1]>0;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        int L = 1, R = 1e9;
        while(L<=R){
           int mid = L + (R-L)/2;
            if(check(mid)){
                L = mid + 1;
            } else{
                R = mid - 1;
            }
        }
        cout << R << endl;
    }
    return 0;
}
