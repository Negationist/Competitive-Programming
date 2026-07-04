#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int MOD = 1e9+7;

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
        int ans = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            ans+=a[i];
        }
        int sum = a[0], mx = a[0];
        for(int i=1;i<n;i++){
            sum = max(sum+a[i],a[i]);
            sum = max(sum,0LL);
            mx = max(sum,mx);
        }
        sum = (sum%MOD + MOD)%MOD;
        for(int i=1;i<=k;i++){
            ans+=mx;
            ans%=MOD;
            mx*=2;
            mx%=MOD;
        }
        cout << (ans+MOD)%MOD << "\n";
    }
    return 0;
}
