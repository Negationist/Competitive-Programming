#include <bits/stdc++.h>

using namespace std;

int arr[200001];
int n;
int memo[200001] ={};

int path(int i){
    if(i>n) return 0;
    if(memo[i]!=0) return memo[i];
    memo[i] = arr[i]+path(i+arr[i]);
    return memo[i];
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int ans =0;
        cin >> n;
        for(int i=1;i<=n;i++){
            int a;
            cin >> a;
            arr[i] = a;
        }
        for(int i=1;i<=n;i++){
            int sum = path(i);
            ans = max(ans,sum);
        }
        fill(memo,memo+n+2,0);
        cout << ans << endl;
    }
    return 0;
}
