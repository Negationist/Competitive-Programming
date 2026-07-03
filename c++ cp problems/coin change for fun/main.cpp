#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int n,k,ans=0;
int arr[10000] = {0};

void solve(int k,int i){
    int orgK = k;
    if (k<0) return;
    if (k==0) ans++;
    if(i>=n) return;
    solve(k-arr[i],i);
    solve(k,i+1);
}

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    solve(k,0);
    cout << ans;
    return 0;
}
