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
    int n,k,g;
    cin >> n >> k >> g;
    int per = (g+1)/2-1;
    int ans = per*(n-1);
    int give = k*g-ans;
    if(give%g<=per){
        ans+=give%g;
    } else{
        ans-=(g-give%g);
    }
    cout << min(ans,k*g) << "\n";
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
