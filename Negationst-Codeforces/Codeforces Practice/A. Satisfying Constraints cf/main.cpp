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
    int mn = -1;
    int mx = LLONG_MAX;
    set<int> s;
    for(int i=0;i<n;i++){
        int z,a;
        cin >> z >> a;
        if(z==1) mn = max(mn, a);
        else if(z==2) mx = min(mx,a);
        else s.insert(a);
    }
    int ans = mx-mn+1;
    for(int x : s){
        if(x>=mn && x<= mx){
            ans--;
        }
    }
    cout << max(ans,0LL) << "\n";
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
