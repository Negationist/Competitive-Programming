#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
void solve(){
    int n;
    cin >> n;
    bool taken = false;
    vi real;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        if(z){
            real.pb(z);
        } else{
            if(!taken){
                real.pb(z);
                taken = true;
            }
        }
    }
    n = real.size();
    int mn[n];
    mn[0] = real[0];
    for(int i=1;i<n;i++){
        mn[i] = min(mn[i-1],real[i]);
    }
    int mex[n];
    int inc = 0;
    map<int,bool> seen;
    for(int i=n-1;i>=0;i--){
        seen[real[i]] = true;
        while(seen[inc]) ++inc;
        mex[i] = inc;
    }
    bool fail = false;
    for(int i=0;i<n-1;i++){
        if(mn[i]<mex[i+1]){
            fail = true;
        }
    }
    cout << n-fail << "\n";
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
