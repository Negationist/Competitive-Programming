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
    vi a(n);
    map<int,int> m;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        m[z]++;
    }
    int ones = 0;
    int rest = 0;
    for(auto x : m){
        if(x.ss==1){
            ones++;
        } else{
            rest++;
        }
    }
    int ans = 0;
    ans+=(ones/2)*2;
    ans+=(ones%2==1)*2;
    ans+=rest;
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
