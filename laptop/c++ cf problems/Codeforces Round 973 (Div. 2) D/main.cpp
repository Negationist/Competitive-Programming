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
        int n;
        cin >> n;
        int mx = 0,mn=LONG_MAX;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        bool go = true;
        while(go){
            go = false;
            for(int i=1;i<n;i++){
                if(a[i] < a[i-1]){
                go = true;
                int sum = a[i]+a[i-1];
                if(sum%2==0){
                    a[i] = a[i-1] = sum/2;
                } else{
                    a[i] = sum/2+1;
                    a[i-1] = sum/2;
                }
            }
            }
        }
        for(int i=0;i<n;i++){
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
        }
        cout << mx-mn << endl;
    }
    return 0;
}
