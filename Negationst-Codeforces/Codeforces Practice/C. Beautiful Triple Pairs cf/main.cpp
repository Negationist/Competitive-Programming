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
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    map<tuple<int,int,int>,int> m;
    map<tuple<int,int,int>,int> m2;
    int ans = 0;
    for(int i=0;i<n-2;i++){
        tuple<int,int,int> trip = {a[i], a[i+1], a[i+2]};
        tuple<int,int,int> t1 = {0LL, a[i+1], a[i+2]};
        tuple<int,int,int> t2 = {a[i], 0LL, a[i+2]};
        tuple<int,int,int> t3 = {a[i], a[i+1], 0LL};
        m2[trip]++;
        int decr = m2[trip]-1;
        decr*=3;
        ans-=decr;
        m[t1]++;
        m[t2]++;
        m[t3]++;
    }
    for(auto x : m){
        int cnt = x.second;
        if(cnt<2) continue;
        ans+=(cnt)*(cnt-1)/2;
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
