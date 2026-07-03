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
    int n;
    cin >> n;
    int ans = 0;
    int mx[105] = {};
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        for(int i=0;i<=a;i++){
            mx[i]=max(mx[i],b);
        }
    }
    for(int i=0;i<105;i++){
        if(mx[i]==0) break;
        ans+=(mx[i]*2+2);
        if(i==0) continue;
        ans-=2*mx[i];
    }
    cout << ans << "\n";
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
