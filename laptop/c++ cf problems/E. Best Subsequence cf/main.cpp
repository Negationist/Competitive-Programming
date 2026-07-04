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
    vii a(n);
    int cnt[64] = {};
    int tot = 0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        a[i] = {z,1};
        tot|=a[i].first;
        for(int i=63;i>=0;i++){
            if(a[i].first&(1<<i)){
                cnt[i]++;
            }
        }
    }
    int ans = n-__builtin_popcountll(tot);
    while(true){
        for(int i=0;i<n;i++){
            if(!)
        }
    }
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
