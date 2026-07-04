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
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int l = (k+1)/2;
        int r = k-l;
        int ans = 0;
        for(int i=0;i<n;i++){
            l-=a[i];
            if(l>=0){
                ans++;
            } else{
                a[i] = -1*l;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            r-=a[i];
            if(r>=0){
                ans++;
            } else{
                break;
            }
        }
        cout << min(n,ans) << endl;
    }
    return 0;
}
