#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,ans=0;
    cin >> n;
    int a[n];
    bool same = true;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        if(n%i==0){
            int GCD = 0;
            for(int j=0;j+i<n;j++){
                GCD = gcd(GCD, abs(a[j] - a[j+i]));
            }
            ans+=(GCD!=1);
        }
    }
    cout << "ans is " << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
