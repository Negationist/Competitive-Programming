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
    int t;
    cin >> t;
    while(t--){
        int n,sum=0;
        int mn = LLONG_MAX,mx = 0;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
            mn = min(mn,a[i]);
        }
        for(int i=0;i<n-1;i++){
            int target = sum/(n-i);
            int cSum = a[i]+a[i+1];
            if(a[i]>target){
                a[i] = target;
                a[i+1] = cSum - a[i];
            }
            if(a[i+1]<target){
                if(cSum%2==1){
                    a[i] = cSum/2;
                    a[i+1] = cSum/2+1;
                } else{
                    a[i] = a[i+1] = cSum/2;
                }
            }
            sum-=a[i];
        }
        mn = LLONG_MAX;
        for(int i=0;i<n;i++){
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
        }
        cout << mx-mn << "\n";
    }
    return 0;
}
