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
        int mx = 0,mn = LLONG_MAX;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            mx = max(mx,a);
            mn = min(mn,a);
        }
        cout << mx-mn << "\n";
    }
    return 0;
}
