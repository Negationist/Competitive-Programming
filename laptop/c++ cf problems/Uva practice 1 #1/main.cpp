#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,ans=0;
    cin >> n >> a;
    int arr[n];
    for(int i=0;i<n;i++){
            cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++){
        a-=(arr[i]+1);
        if(a>=0){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
